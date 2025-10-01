## 1. Entender el objetivo del proyecto

El proyecto consiste en:

- Cargar un mapa 2D (.cub) con paredes, suelos, techos y la posición del jugador.

- Renderizarlo en una ventana con raycasting para simular un entorno 3D estilo Wolfenstein 3D.

- Mover al jugador con las teclas W, A, S, D y rotar la cámara con las flechas izquierda/derecha.

- Gestionar texturas para cada dirección de pared (N, S, E, O), y colores distintos para suelo/techo.

El corazón es **raycasting**, una técnica matemática que convierte el mapa 2D en una vista pseudo-3D.




## 2. Dividir el proyecto en fases

Una buena estrategia en pareja es separar tareas claras:

### Fase 1: Preparación del entorno

- Compilar con MiniLibX (ventana + imágenes + eventos de teclado).

- Crear la ventana y asegurarse de que se abre/cierra correctamente con ESC o la “X”.


### Fase 2: Parser del mapa .cub

- Leer archivo `.cub`.

- Guardar texturas (`NO`, `SO`, `WE`, `EA`).

- Guardar colores de suelo (F) y techo (C).

- Guardar el mapa en una matriz 2D.

- Verificar:

    - El mapa está cerrado por paredes (1).

    - Hay solo un jugador y con orientación (N, S, E, W).

    - Errores → imprimir "Error\n" + mensaje.


### Fase 3. Movimiento del jugador

- Estuctura con posicion`(x, y)`y dirección inicial.
- Capturar eventos de teclado:
    - `W, A, S, D`
    - Flechas -> rotar dirección.
- Comprobar colsiones con el mapa(no atravesar paredes).


### Fase 4 Raycasting

Este es el núcleo. Para cada columna de la ventana:

1. Lanza un rayo desde la posición del jugador.

2. Detecta en qué celda del mapa choca con una pared.

3. Calcula la distancia.

4. Dibuja una “barra” proporcional a esa distancia.

Luego:
- Diferenciar textras segun lado de impacto (N, S, E, O).
- Aplicar los colores del suelo/techo.


### Fase 5 Bonus

- Minimapa
- Colisiones realista
- Mouse look
- Puertas animadas.


## 3. División de proyecto

1. Parseo del mapa + gestion de errores.
2. MLX

Juntos: Raycasting.




# Normas

- [X] Techo y suelo de distinto color
