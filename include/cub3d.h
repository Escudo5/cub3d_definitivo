/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:50:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/11/06 22:06:39 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System libraries
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

// User Libraries
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

/* Constantes de ventana por defecto (ajusta luego con el parser .cub) */
# define WIN_W 800
# define WIN_H 600
# define TITLE "cub3d"

/*Macros for error*/
enum				e_macro_errors
{
	SUCCESS = 0,
	MALLOC_ERROR = -1,
	INPUT_ERROR = -2,
	INVALID_COLOR = -3
};

/* Imagen de frame: buffer donde pintas antes de mostrar en la ventana */
typedef struct s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				w;
	int				h;
}					t_img;

/* Handles de MiniLibX */
typedef struct s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

/* Configuración general (resolución, colores básicos) */
typedef struct s_color
{
	long			t;
	long			r;
	long			g;
	long			b;
}					t_color;

typedef struct s_cfg
{
	int				w;
	int				h;
	t_color			ceil_color;
	t_color			floor_color;
}					t_cfg;

/* Vectores 2D en double para precisión en raycasting y movimiento */
typedef struct s_vec2
{
	double			x;
	double			y;
}					t_vec2;

/* Estado del jugador y cámara */
typedef struct s_player
{
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			plane;
}					t_player;

// Struct for storing the map
typedef struct s_map
{
	int				w;
	int				h;
	char			**grid;
}					t_map;

typedef struct s_keys
{
	int				esc;
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_keys;

typedef struct s_ray
{
	double			camera_x;
	t_vec2			ray_dir; // direccion del rayo en 2D
	int				map_x;
	int				map_y; // celda del mapa actual donde se busca la paredd
	double			side_dist_x;
	double			side_dist_y;
	// distancia dle jugador al borde en x/y que alcanza el rayo
	double			delta_dist_x;
	double			delta_dist_y;
	// cuanto hay que avanzar a lo largo del rayo para cruzar una celda en x/y
	int				step_x;
	int				step_y; // direccion del paso en el mapa
	int				side;
	double			perp_dist; // calculo de altura de muro.
	int				hit;
}					t_ray;

typedef struct s_slice
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			tex_step;
	double			tex_pos;
	// posicion inicial en la textura para el primer pixel de draw_start.
}					t_slice;

typedef struct s_path
{
	char			*n;
	char			*s;
	char			*w;
	char			*e;
}					t_path;

typedef struct s_player_start
{
	int				y;
	int				x;
	char			orientation;
}					t_player_start;

typedef struct s_fck_pl_mv
{
	double			new_x;
	double			new_y;
	double			old_x;
	double			old_y;
	int				ix_newx;
	int				iy_newy;
	int				ix_oldx;
	int				iy_oldy;
}					t_fck_pl_mv;

/* Contexto global: pasarás un puntero a esto a todas las funciones */
typedef struct s_ctx
{
	t_mlx			mlx;
	t_img			frame;
	t_img			tex_north;
	t_img			tex_south;
	t_img			tex_east;
	t_img			tex_west;
	t_cfg			cfg;
	t_player		player;
	t_player_start	player_start;
	t_map			map;
	t_keys			keys;
	t_ray			ray;
	t_slice			slice;
	t_vec2			vec2;
	t_path			path;
	t_fck_pl_mv		movement;
}					t_ctx;

// raycasting

void				calc_ray(t_ctx *rc);
void				dda(t_ctx *rc);
void				wall_dist(t_ctx *rc);
void				calc_tex_pos(t_ctx *rc);
void				raycast(t_ctx *rc);

// render
void				put_pixel(t_ctx *rc, int x, int y, uint32_t color);
unsigned int		get_pixel(t_ctx *rc, int x, int y);
void				draw_background(t_ctx *rc, int c);
void				draw_env(t_ctx *rc, int start_y, int end_y);
void				draw_mix(t_ctx *rc);

// texture

int					set_color(t_color color);
t_color				get_color(int color);
t_img				*search_img(char *tex, t_ctx *rc);
t_img				*get_wall_tex(t_ctx *rc);
void				draw_tex(t_ctx *rc, int x);

// img_utils

// hooks

int					hook_close(t_ctx *c);
int					hook_key_press(int keycode, t_ctx *c);
int					hook_key_release(int keycode, t_ctx *c);

// init

int					game_init(t_ctx *ctx);
int					gfx_open(t_ctx *ctx);
int					gfx_create_frame(t_ctx *c);
int					load_texture(t_ctx *c, t_img *texture, char *path);
int					load_textures(t_ctx *c);
void				init_player(t_ctx *ctx);
int					map_test(t_ctx *ctx);

void				game_destroy(t_ctx *c, int code);
int					app_loop(t_ctx *c);

// movement
void				move_forward(t_ctx *ctx, double mov_speed);
void				move_backward(t_ctx *ctx, double mov_speed);
void				move_right(t_ctx *ctx, double mov_speed);
void				move_left(t_ctx *ctx, double move_speed);
void				handle_movement(t_ctx *c);

// camera
void				rotate_camera(t_ctx *ctx, double rot_speed);

#endif