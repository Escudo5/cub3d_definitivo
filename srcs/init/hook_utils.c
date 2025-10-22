/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:44:30 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/22 15:39:09 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

int	hook_close(t_ctx *c)
{
	game_destroy(c, 0);
	return (0);
}

int	hook_key_press(int keycode, t_ctx *c)
{
	if (keycode == 65307)
	game_destroy(c, 0);
	if (keycode == 119)
	c->keys.w = 1;
	if (keycode == 115)
	c->keys.s = 1;
	if (keycode == 97)
	c->keys.a = 1;
	if (keycode == 100)
	c->keys.d = 1;
	if (keycode == 65361)
	c->keys.left = 1;
	if (keycode == 65363)
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
