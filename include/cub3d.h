/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:50:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/15 17:06:13 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

/* Constantes de ventana por defecto (ajusta luego con el parser .cub) */
# define WIN_W 800
# define WIN_H 600
# define TITLE "cub3d"

/* Imagen de frame: buffer donde pintas antes de mostrar en la ventana */
typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			w;
	int			h;
}				t_img;

/* Handles de MiniLibX */
typedef struct s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

/* Configuración general (resolución, colores básicos) */
typedef struct s_cfg
{
	int			w;
	int			h;
	uint32_t	ceil_color;
	uint32_t	floor_color;
}				t_cfg;

/* Vectores 2D en double para precisión en raycasting y movimiento */
typedef struct s_vec2
{
	double		x;
	double		y;
}				t_vec2;

/* Estado del jugador y cámara */
typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
}				t_player;

typedef struct s_map
{
	int			w;
	int			h;
	char		**grid;
}				t_map;

typedef struct s_keys
{
	int			esc;
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

/* Contexto global: pasarás un puntero a esto a todas las funciones */
typedef struct s_ctx
{
	t_mlx		mlx;
	t_img		frame;
	t_cfg		cfg;
	t_player	player;
	t_map		map;
	t_keys		keys;
}				t_ctx;

/* Prototipos mínimos para los primeros sprints (ajusta según módulos) */
int				app_init(t_ctx *c);
int				app_loop(t_ctx *c);
void			app_destroy(t_ctx *c, int code);

/* GFX */
int				gfx_open(t_ctx *c);
int				gfx_create_frame(t_ctx *c);
void			gfx_clear(t_ctx *c, uint32_t color);
void			gfx_present(t_ctx *c);
void			gfx_vline(t_ctx *c, int x, int y0, int y1, uint32_t color);

/* Hooks */
int				hook_close(t_ctx *c);
int				hook_key_press(int keycode, t_ctx *c);
int				hook_key_release(int keycode, t_ctx *c);

#endif