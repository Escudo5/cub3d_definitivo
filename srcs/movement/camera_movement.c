/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:13:12 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/29 18:23:06 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_camera(t_ctx *ctx, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ctx->player.dir.x;
	old_plane_x = ctx->player.plane.x;
	ctx->player.dir.x = old_dir_x * cos(rot_speed) - ctx->player.dir.y
		* sin(rot_speed);
	ctx->player.dir.y = old_dir_x * sin(rot_speed) + ctx->player.dir.y
		* cos(rot_speed);
	ctx->player.plane.x = ctx->player.plane.x * cos(rot_speed)
		- ctx->player.plane.y * sin(rot_speed);
	ctx->player.plane.y = old_plane_x * sin(rot_speed) + ctx->player.plane.y
		* cos(rot_speed);
}
