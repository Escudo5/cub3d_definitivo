/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:32:17 by escudo5           #+#    #+#             */
/*   Updated: 2025/10/17 16:30:38 by escudo5          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

//calcular step y side_dist iniciales

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


//parseo completo para veitar errores de mapa.

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

//obtener line_height, draw start y end.






////////Falta funcion que calcule la posicion de la textura






void	raycast(t_ctx *rc, t_mlx *mlx)
{
	int	x;

	x = -1;
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

        //falta calcular texctura de pared y dibujarla
	}
}

// init ray y calular direccion todo en la misma funcion
// a partir de la posicion inical calcula las distancias.