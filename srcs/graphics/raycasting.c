/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:32:32 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/29 18:20:34 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calc_ray(t_ctx *rc)
{
	if (rc->ray.ray_dir.x < 0)
	{
		rc->ray.step_x = -1;
		rc->ray.side_dist_x = (rc->player.pos.x - rc->ray.map_X)
			* rc->ray.delta_dist_x;
	}
	else
	{
		rc->ray.step_x = 1;
		rc->ray.side_dist_x = (rc->ray.map_X + 1.0 - rc->player.pos.x)
			* rc->ray.delta_dist_x;
	}
	if (rc->ray.ray_dir.y < 0)
	{
		rc->ray.step_y = -1;
		rc->ray.side_dist_y = (rc->player.pos.y - rc->ray.map_Y)
			* rc->ray.delta_dist_y;
	}
	else
	{
		rc->ray.step_y = 1;
		rc->ray.side_dist_y = (rc->ray.map_Y + 1.0 - rc->player.pos.y)
			* rc->ray.delta_dist_y;
	}
}

// calcular step y side_dist iniciales

void	dda(t_ctx *rc)
{
	while (rc->ray.hit == 0)
	{
		if (rc->ray.side_dist_x < rc->ray.side_dist_y)
		{
			rc->ray.side_dist_x += rc->ray.delta_dist_x;
			rc->ray.map_X += rc->ray.step_x;
			rc->ray.side = 0;
		}
		else
		{
			rc->ray.side_dist_y += rc->ray.delta_dist_y;
			rc->ray.map_Y += rc->ray.step_y;
			rc->ray.side = 1;
		}
		if (rc->map.grid[rc->ray.map_Y][rc->ray.map_X] == '1')
			rc->ray.hit = 1;
	}
	if (rc->ray.side == 0)
		rc->ray.perp_dist = (rc->ray.map_X - rc->player.pos.x + (1
					- rc->ray.step_x) / 2) / rc->ray.ray_dir.x;
	else
		rc->ray.perp_dist = (rc->ray.map_Y - rc->player.pos.y + (1
					- rc->ray.step_y) / 2) / rc->ray.ray_dir.y;
}

// parseo completo para veitar errores de mapa.

void	wall_dist(t_ctx *rc)
{
	rc->slice.line_height = (int)(rc->cfg.h / rc->ray.perp_dist);
	rc->slice.draw_start = -rc->slice.line_height / 2 + rc->cfg.h / 2;
	if (rc->slice.draw_start < 0)
		rc->slice.draw_start = 0;
	rc->slice.draw_end = rc->slice.line_height / 2 + rc->cfg.h / 2;
	if (rc->slice.draw_end >= rc->cfg.h)
		rc->slice.draw_end = rc->cfg.h - 1;
}

// obtener line_height, draw start y end.

void	calc_tex_pos(t_ctx *rc)
{
	t_img	*image;

	image = get_wall_tex(rc);
	if (rc->ray.side == 0)
		rc->slice.wall_x = rc->player.pos.y + rc->ray.perp_dist
			* rc->ray.ray_dir.y;
	else
		rc->slice.wall_x = rc->player.pos.x + rc->ray.perp_dist
			* rc->ray.ray_dir.x;
	rc->slice.wall_x -= floor(rc->slice.wall_x);
	rc->slice.tex_x = (int)(rc->slice.wall_x * (double)image->w);
	if (rc->ray.side == 0 && rc->ray.ray_dir.x > 0)
		rc->slice.tex_x = (double)image->w - rc->slice.tex_x - 1;
	if (rc->ray.side == 1 && rc->ray.ray_dir.y < 0)
		rc->slice.tex_x = (double)image->w - rc->slice.tex_x - 1;
	rc->slice.tex_step = 1.0 * image->h / rc->slice.line_height;
	rc->slice.tex_pos = (rc->slice.draw_start - rc->cfg.h / 2
			+ rc->slice.line_height / 2) * rc->slice.tex_step;
}

void	raycast(t_ctx *rc)
{
	int	x;

	x = -1;
	draw_mix(rc);
	while (++x < rc->cfg.w)
	{
		rc->ray.camera_x = 2 * x / (double)rc->cfg.w - 1;
		rc->ray.ray_dir.x = rc->player.dir.x + rc->player.plane.x
			* rc->ray.camera_x;
		rc->ray.ray_dir.y = rc->player.dir.y + rc->player.plane.y
			* rc->ray.camera_x;
		rc->ray.map_X = (int)rc->player.pos.x;
		rc->ray.map_Y = (int)rc->player.pos.y;
		rc->ray.delta_dist_x = fabs(1.0 / rc->ray.ray_dir.x);
		rc->ray.delta_dist_y = fabs(1.0 / rc->ray.ray_dir.y);
		rc->ray.hit = 0;
		calc_ray(rc);
		dda(rc);
		wall_dist(rc);
		calc_tex_pos(rc);
		draw_tex(rc, x);
	}
	mlx_put_image_to_window(rc->mlx.ptr, rc->mlx.win, rc->frame.ptr, 0, 0);
}

// init ray y calular direccion todo en la misma funcion
// a partir de la posicion inical calcula las distancias.