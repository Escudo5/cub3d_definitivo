## Apuntes funcionamiento

Imagina la pantalla como un plano de coordenadas, como el eje X. Que va desde la izquierda de la pantalla hacia la derecha.

Por cada X en la pantalla, se lanza un rayo que empieza en la posicion del jugador con la direccion que depende de la direccion en la que mira y la coordenada X de la pantalla.

Este rayo se mueve en 2D en el mapa, hasta que choca con una pared.

Si choca con una pared, calcula la distancia desde el jugador hasta el muro para calcular la altura de la pared y poder dibujarla.



## Direccion de jugador y vector de la camara

Antes de lanzar rayos, tenemos que determinar donde castear los rayos. Tenemos que saber en que direccion mira el personaje, lo hacemos con un vector.

![Imagen fov jugador](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/player_dir_vect.png "Imagen del jugador")


La direccion se puede definir como el vector con X e Y. (y = 1,  x = 0).

El vector de la camara es perpendicular a la direccion del vector del jugador.

![Vector de la camara](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/cam_vect.png "Vector de la camara")

Ahora podemos conectar los extremos de ambos vectores y tenemos un cono con el campo de vision.

Si el vector es mucho mas largo que el plano de la camara, el FOV será mas pequeño que 90º y tendras vision estrecha.

![Campo de vision alejado](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/cam_vect_3.png "Campo de vision alejado")


## Algoritmo DDA (Digital Differential Analysis)

Determina la altura de la pared a dibujar.

Calcula que cuadrados de nuestro mapa atraviesa el rayo.

![Camino del rayo hasta el muro](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/DDA2.png "Camino del rayo hasta el muro")

Si alguno de los cuadrados por los que pasa es un muro, el rayo se para.

Como la distancia entre cuadrados es constante, podemos multiplicar los deltas entre las intersecciones de los rayos y los bordes para sacar la longitud del rayo.


## Implementación

Declaramos variables para el personaje y su FOV.

```c

int main(int argc, char *argv[])
{
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
}
```

Continuamos con el loop de minilibx (mlx_loop_hook).

A partir de aqui empieza el raycasting, lanzamos un rayo para cada pixel de la longitud de la pantalla.


```c

    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
    }
```


- En el siguiente codigo **mapX y mapY** representan el ***cuadrado del mapa en los que esta el rayo***.
La posicion del rayo es un float que contiene info de en cual cuadrado estamos y en que parte dentro de ese cuadrado.

- sideDistX y sideDistY es la distancia que el rayo viaja desde la posicio inicial hasta el primer lado x y lado y.
- deltaDistX y deltaDistY es a distancia que viaja el rayo desde un lado x hasta el siguiente lado x o igual para los lados y.

![WTF does this mean ???](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/rc_implement.png "WTF does this mean ???")


Para sacar deltaDistX y deltaDistY usamos esto: 

```c
deltaDistX = abs(1 / rayDirX)
deltaDistY = abs(1 / rayDirY)
```

resumen? 
```c
      //which box of the map we're in
      int mapX = int(posX);
      int mapY = int(posY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
```

Antes de empezar con el DDA tenemos que calcular el resto de variables.
```c
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
```

Metemos el DDA en un bucle que incrementa los cuadrados del mapa hasta que choca con un muro. Va saltando cuadrados de 1 en 1 en X o Y.

```c
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 
```


## Vector del plano de la camara.

Despues del DDA, tenemos que calcular la distancia del rayo al muro para poder calcular la altura de la pared.

Para evitar el ojo de pez usamos el plano de la camara en lugar del jugador para calcular la distancia.

![Calculo de distancia del jugador al muro](https://raw.githubusercontent.com/neosizzle/cub3d/main/pictures/fish_eye_2.png "Calculo de distancia del jugador al muro")


## Escalado de imagen y transformacion MLX

Una vez sabemos la distancia hasta el muro, usamos los datos para dibujar.

### Struct con datos

```c
typedef  struct  s_line
{
	int  x; //the x coordinate of line relative to screen
	int  y; //the current pixel index of the line (along y axis)
	int  y0; //y start index of drawing texture
	int  y1; //y end index of drawing texture
	int  tex_x; //x coordinate of texture to draw
	int  tex_y; //y coordinate of texture to draw
} t_line;
```


