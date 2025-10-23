/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:42:16 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 17:55:13 by smarquez         ###   ########.fr       */
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
	if (!load_textures(ctx))
	return(0);
	
	init_player(ctx);
	printf("he entrado en init_player\n");
	mlx_hook(ctx->mlx.win, 2, 1L << 0, hook_key_press, ctx);
	mlx_hook(ctx->mlx.win, 3, 1L << 1, hook_key_release, ctx);
	mlx_hook(ctx->mlx.win, 17, 0, hook_close, ctx);
	return(1);
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
	if (!load_texture(c, &c->tex_north, "./textures/Minecraft_diamond.xpm"))
	    return (0);
	if (!load_texture(c, &c->tex_south, "./textures/Minecraft_esmerald.xpm"))
		return (0);
	if (!load_texture(c, &c->tex_east, "./textures/Minecraft_gold.xpm"))
		return (0);
	if (!load_texture(c, &c->tex_west, "./textures/Minecraft_lapis.xpm"))
		return (0);
				
	return (1);
}
int map_test(t_ctx *ctx)
{
    static char *map[] = {
        "11111",
        "10001",
        "10N01",
        "10001",
        "11111",
        NULL
    };
    ctx->map.grid = map;
    ctx->map.h = 5;
    ctx->map.w = 5;
    for (int y = 0; y < ctx->map.h; y++)
        printf("%s\n", ctx->map.grid[y]);
    return (0);
}