/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:43 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/29 17:20:28 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"
# include "../../include/parser.h"

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
	free_paths(c);
	free_grid(c->map.grid, "Exit\n", SUCCESS);
	free(c);
	exit(code);
}

int	main(int argc, char **argv)
{
	t_ctx *ctx;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	ctx = ft_calloc(1, sizeof(t_ctx));
	if (!ctx)
		return (EXIT_FAILURE);
	if (parser(argv[1], ctx) != SUCCESS)
	{
		ft_putstr_fd("Parser failed\n", 2);
		free_paths(ctx);
		free(ctx);
		return (EXIT_FAILURE);
	}
	if (!game_init(ctx))
	{
		game_destroy(ctx, 1);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(ctx->mlx.ptr, app_loop, ctx);
	mlx_loop(ctx->mlx.ptr);
	return (EXIT_SUCCESS);
}
