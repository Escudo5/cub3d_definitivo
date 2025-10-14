## Apuntes funcionamiento

Imagina la pantalla como un plano de coordenadas, como el eje X. Que va desde la izquierda de la pantalla hacia la derecha.

Por cada X en la pantalla, se lanza un rayo que empieza en la posicion del jugador con la direccion que depende de la direccion en la que mira y la coordenada X de la pantalla.

Este rayo se mueve en 2D en el mapa, hasta que choca con una pared.

Si choca con una pared, calcula la distancia desde el jugador hasta el muro para calcular la altura de la pared y poder dibujarla.



## Direccion de jugador y vector de la camara

Antes de lanzar rayos, tenemos que determinar donde castear los rayos. Tenemos que saber en que direccion mira el personaje, lo hacemos con un vector.

![Imagen fov jugador](https://hackmd.io/@nszl/H1LXByIE2?stext=5178%3A103%3A0%3A1760438169%3Ap8vdpI)


La direccion se puede definir como el vector con X e Y. (y = 1,  x = 0).

El vector de la camara es perpendicular a la direccion del vector del jugador.

![Vector de la camara](https://hackmd.io/@nszl/H1LXByIE2?stext=5723%3A89%3A0%3A1760438433%3Ag5sdro)

Ahora podemos conectar los extremos de ambos vectores y tenemos un cono con el campo de vision.

Si el vector es mucho mas largo que el plano de la camara, el FOV será mas pequeño que 90º y tendras vision estrecha.

![Campo de vision alejado](https://hackmd.io/@nszl/H1LXByIE2?stext=6246%3A93%3A0%3A1760438622%3AqYVFkE)


## Algoritmo DDA (Digital Differential Analysis)

Determina la altura de la pared a dibujar.

Calcula que cuadrados de nuestro mapa atraviesa el rayo.

![Camino del rayo hasta el muro](https://hackmd.io/@nszl/H1LXByIE2?stext=7130%3A81%3A0%3A1760438903%3AAy7xrd)