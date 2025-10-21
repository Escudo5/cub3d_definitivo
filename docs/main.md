Funciones y orden

1. game init, asigna medidas de pantalla, llama a graphics_open, gfx_create_frame, load_tex. Despues llama a init_player y los hooks.
2. gfx_open asigna el ptr a mlx_init, el param win = mlx_new_window.
3. gfx_create_frame asigna ptr a mlx_new_image, el addr = mlx_new_data_addr, despues de comprbaciones de existencia asignamos frame.w y frame.h con cfg.w y cfg.h.
4. load_etxture asigna ptr a mlx_xpm_file_to_image, texture->addr = mlx_get_data_addr
5. Funcion muy parecida a la anterior pero ahora cargamos las texturas de los archivos. Para ello usamos la funcion anterior con la textura que corresponde y la ruta de archivo.


## Funciones de movimiento

delante, atras y lados.


Funcion auxiliar de destruccion de imagen.