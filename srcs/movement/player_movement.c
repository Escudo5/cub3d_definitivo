/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:34:32 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/29 18:32:31 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_ctx *ctx, double mov_speed)
{
	ctx->movement.new_x = ctx->player.pos.x + ctx->player.dir.x * mov_speed;
	ctx->movement.new_y = ctx->player.pos.y + ctx->player.dir.y * mov_speed;
	ctx->movement.old_x = ctx->player.pos.x;
	ctx->movement.old_y = ctx->player.pos.y;
	ctx->movement.ix_newx = (int)ctx->movement.new_x;
	ctx->movement.iy_newy = (int)ctx->movement.new_y;
	ctx->movement.ix_oldx = (int)ctx->movement.old_x;
	ctx->movement.iy_oldy = (int)ctx->movement.old_y;
	if (ctx->movement.iy_oldy >= 0 && ctx->movement.iy_oldy < ctx->map.h
		&& ctx->movement.ix_newx >= 0 && ctx->movement.ix_newx < ctx->map.w
		&& ctx->map.grid[ctx->movement.iy_oldy][ctx->movement.ix_newx] != '1')
		ctx->player.pos.x = ctx->movement.new_x;
	if (ctx->movement.iy_newy >= 0 && ctx->movement.iy_newy < ctx->map.h
		&& ctx->movement.ix_oldx >= 0 && ctx->movement.ix_oldx < ctx->map.w
		&& ctx->map.grid[ctx->movement.iy_newy][ctx->movement.ix_oldx] != '1')
		ctx->player.pos.y = ctx->movement.new_y;
}

void	move_backward(t_ctx *ctx, double mov_speed)
{
	ctx->movement.new_x = ctx->player.pos.x - ctx->player.dir.x * mov_speed;
	ctx->movement.new_y = ctx->player.pos.y - ctx->player.dir.y * mov_speed;
	ctx->movement.old_x = ctx->player.pos.x;
	ctx->movement.old_y = ctx->player.pos.y;
	ctx->movement.ix_newx = (int)ctx->movement.new_x;
	ctx->movement.iy_newy = (int)ctx->movement.new_y;
	ctx->movement.ix_oldx = (int)ctx->movement.old_x;
	ctx->movement.iy_oldy = (int)ctx->movement.old_y;
	if (ctx->movement.iy_oldy >= 0 && ctx->movement.iy_oldy < ctx->map.h
		&& ctx->movement.ix_newx >= 0 && ctx->movement.ix_newx < ctx->map.w
		&& ctx->map.grid[ctx->movement.iy_oldy][ctx->movement.ix_newx] != '1')
		ctx->player.pos.x = ctx->movement.new_x;
	if (ctx->movement.iy_newy >= 0 && ctx->movement.iy_newy < ctx->map.h
		&& ctx->movement.ix_oldx >= 0 && ctx->movement.ix_oldx < ctx->map.w
		&& ctx->map.grid[ctx->movement.iy_newy][ctx->movement.ix_oldx] != '1')
		ctx->player.pos.y = ctx->movement.new_y;
}

void	move_right(t_ctx *ctx, double mov_speed)
{
	double	new_x;
	double	new_y;

	new_x = ctx->player.pos.x + (-ctx->player.dir.y * mov_speed);
	new_y = ctx->player.pos.y + (ctx->player.dir.x * mov_speed);
	if (ctx->map.grid[(int)new_y][(int)new_x] != '1')
	{
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
}

void	move_left(t_ctx *ctx, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = ctx->player.pos.x + (ctx->player.dir.y * move_speed);
	new_y = ctx->player.pos.y + (-ctx->player.dir.x * move_speed);
	if (ctx->map.grid[(int)new_y][(int)new_x] != '1')
	{
		ctx->player.pos.x = new_x;
		ctx->player.pos.y = new_y;
	}
}

void	handle_movement(t_ctx *c)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.01;
	rot_speed = 0.01;
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
