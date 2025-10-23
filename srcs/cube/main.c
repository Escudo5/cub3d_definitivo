/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:43 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 17:17:41 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

int	app_loop(t_ctx *c)
{
	handle_movement(c);
	raycast(c);
	return (0);
}



void	game_destroy(t_ctx *c, int code)
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
	
	// if (c->map.grid)
	// free_map(c);
	
	printf("game_Destory\n");
	exit(code);
}

int	main(int argc, char **argv)
{
	t_ctx *ctx;
	
	if (argc != 2 && argv)
		printf("hi");
	ctx = ft_calloc(1, sizeof(t_ctx));

	//ft_memset(&ctx, 0, sizeof(t_ctx));
	// if (argv[0])
	// 	printf("A\n");
	// if(!parse_file(argv[1],  &ctx))
	// 	return(1);
	map_test(ctx);
	if (!game_init(ctx))
	{
		game_destroy(ctx, 1);
		printf("!game_init\n");
		return(1);
	}
	mlx_loop_hook(ctx->mlx.ptr, app_loop, ctx);
	mlx_loop(ctx->mlx.ptr);
}