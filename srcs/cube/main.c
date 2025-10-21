/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:43 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/21 18:24:05 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"



int game_init(t_ctx *ctx)
{
	ctx->cfg.h = WIN_H;
	ctx->cfg.w = WIN_W;
	
	if (!gfx_open(ctx))
	return(0);
	if (!gfx_create_frame(ctx))
	return(0);
	if (!load_texture(ctx))
	return(0);
	
	init_player(ctx);
	mlx_hook(ctx->mlx.win, 2, 1L << 0, hook_key_press, ctx);
	mlx_hook(ctx->mlx.win, 3, 1L << 1, hook_key_release, ctx);
	mlx_hook(ctx->mlx.win, 17, 0, hook_close, ctx);
}

int gfx_open(t_ctx *ctx)
{
	ctx->mlx.ptr = mlx_init();
	if (!ctx->mlx.ptr)
	return(0);
	ctx->mlx.win = mlx_new_window(ctx->mlx.ptr, ctx->cfg.w, ctx->cfg.h, TITLE);
	if (!ctx->mlx.win)
	return(0);
	return(1);
}

int	gfx_create_frame(t_ctx *c)
{
	c->frame.ptr = mlx_new_image(c->mlx.ptr, c->cfg.w, c->cfg.h);
	if (!c->frame.ptr)
		return (0);	
	c->frame.addr = mlx_get_data_addr(c->frame.ptr, &c->frame.bpp,
			&c->frame.line_len, &c->frame.endian);
	if (!c->frame.addr)
		return (0);
	c->frame.w = c->cfg.w;
	c->frame.h = c->cfg.h;
	return (1);
}
		
		int	load_texture(t_ctx *c, t_img *texture, char *path)
		{
			int	w;
			int	h;
			
			texture->ptr = mlx_xpm_file_to_image(c->mlx.ptr, path, &w, &h);
			if (!texture->ptr)
			return (0);
			
			texture->addr = mlx_get_data_addr(texture->ptr, &texture->bpp,
				&texture->line_len, &texture->endian);
				if (!texture->addr)
				return (0);
				
				texture->w = w;
				texture->h = h;
				
				return (1);
			}
			
			int	load_textures(t_ctx *c)
			{
				if (!load_texture(c, &c->tex_north, "./textures/north.xpm"))
				return (0);
				if (!load_texture(c, &c->tex_south, "./textures/south.xpm"))
				return (0);
				if (!load_texture(c, &c->tex_east, "./textures/east.xpm"))
				return (0);
				if (!load_texture(c, &c->tex_west, "./textures/west.xpm"))
				return (0);
				
	return (1);
}

void	handle_movement(t_ctx *c)
{
	double	move_speed;
	double	rot_speed;
	
	move_speed = 0.05;
	rot_speed = 0.03;
	
	if (c->keys.w)
	move_forward(c, move_speed);
	if (c->keys.s)
	move_backward(c, move_speed);
	
	if (c->keys.a)
	move_left(c, move_speed);
	if (c->keys.d)
	move_right(c, move_speed);
	
	if (c->keys.left)
	rotate_camera(c, -rot_speed);
	if (c->keys.right)
	rotate_camera(c, rot_speed);
}
int	app_loop(t_ctx *c)
{
	handle_movement(c);
	
	raycast(c);
	
	return (0);
}



void	app_destroy(t_ctx *c, int code)
{
	if (c->tex_north.ptr)
	mlx_destroy_image(c->mlx.ptr, c->tex_north.ptr);
	if (c->tex_south.ptr)
	mlx_destroy_image(c->mlx.ptr, c->tex_south.ptr);
	if (c->tex_east.ptr)
	mlx_destroy_image(c->mlx.ptr, c->tex_east.ptr);
	if (c->tex_west.ptr)
	mlx_destroy_image(c->mlx.ptr, c->tex_west.ptr);
	
	if (c->frame.ptr)
	mlx_destroy_image(c->mlx.ptr, c->frame.ptr);
	
	if (c->mlx.win)
	mlx_destroy_window(c->mlx.ptr, c->mlx.win);
	
	if (c->mlx.ptr)
	{
		mlx_destroy_display(c->mlx.ptr);
		free(c->mlx.ptr);
	}
	
	if (c->map.grid)
	free_map(c);
	
	exit(code);
}


int	hook_close(t_ctx *c)
{
	app_destroy(c, 0);
	return (0);
}

int	hook_key_press(int keycode, t_ctx *c)
{
	if (keycode == 65307)  // ESC
	app_destroy(c, 0);
	if (keycode == 119)    // W
	c->keys.w = 1;
	if (keycode == 115)    // S
	c->keys.s = 1;
	if (keycode == 97)     // A
	c->keys.a = 1;
	if (keycode == 100)    // D
	c->keys.d = 1;
	if (keycode == 65361)  // Left arrow
	c->keys.left = 1;
	if (keycode == 65363)  // Right arrow
	c->keys.right = 1;
	return (0);
}

int	hook_key_release(int keycode, t_ctx *c)
{
	if (keycode == 119)
	c->keys.w = 0;
	if (keycode == 115)
	c->keys.s = 0;
	if (keycode == 97)
	c->keys.a = 0;
	if (keycode == 100)
	c->keys.d = 0;
	if (keycode == 65361)
	c->keys.left = 0;
	if (keycode == 65363)
	c->keys.right = 0;
	return (0);
}
int	main(int argc, char **argv)
{
	t_ctx *ctx;
	
	if (argc != 2)
		return(1);
	ft_memset(&ctx, 0, sizeof(t_ctx));
	if(!parse_file(argv[1],  &ctx))
		return(1);
	if (!game_init(&ctx))
	{
		game_destroy(&ctx, 1);
		return(1);
	}
	mlx_loop_hook(ctx->mlx.ptr, app_loop, &ctx);
	mlx_loop(ctx->mlx.ptr);
}