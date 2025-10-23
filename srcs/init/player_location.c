/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_location.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:46:43 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 17:28:26 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"


void set_player_dir(t_ctx *ctx, char orient)
{
    if(orient == 'N')
    {
        ctx->player.dir.x = 0;
        ctx->player.dir.y = -1;
        ctx->player.plane.x = 0.66;
        ctx->player.plane.y = 0;
        
    }
    else if (orient == 'S')
    {
        ctx->player.dir.x = 0;
        ctx->player.dir.y = 1;
        ctx->player.plane.x = -0.66; 
        ctx->player.plane.y = 0;
    }
    else if (orient == 'E')
    {
        ctx->player.dir.x = 1;
        ctx->player.dir.y = 0;
        ctx->player.plane.x = 0;
        ctx->player.plane.y = 0.66;
    }
    else if (orient == 'W')
    {
        ctx->player.dir.x = -1;
        ctx->player.dir.y = 0;
        ctx->player.plane.x = 0;
        ctx->player.plane.y = -0.66;
    }
}

void init_player(t_ctx *ctx)
{
    int x;
    int y;
    char player_char;

    y = 0;
    while (y < ctx->map.h)
    {
        x = 0;
        while (x < ctx->map.w)
        {
            player_char = ctx->map.grid[y][x];
            if (player_char == 'N' || player_char == 'S' || player_char == 'W' || player_char == 'E')
            {
                ctx->player.pos.x = x + 0.5;
                ctx->player.pos.y = y + 0.5;
                set_player_dir(ctx, player_char);
                return;
            }
            x++;
        }
        y++;
    }
}
