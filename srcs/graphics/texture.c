/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:32:25 by escudo5           #+#    #+#             */
/*   Updated: 2025/10/18 14:02:21 by escudo5          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int set_color(t_color color)
{
    return(color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_color get_color(int color)
{
    t_color col;
    col.t = (color >> 24) & 0xFF;
    col.r = (color >> 16) & 0XFF;
    col.g = (color >> 8) & 0xFF;
    col.b = (color) & 0xFF;
    return(col);
}

t_ctx *get_wall_text(t_ctx *rc)
{
    if (rc->ray.side == 0)
    {
        if (rc->ray.ray_dir.x > 0)
            return(search_img("south", rc->mlx));
        else
            return(search_img("north", rc->mlx));
    }
    else
    {
        if (rc->ray.ray_dir.y > 0)
            return(search_img("west", rc->mlx));
        else
            return(search_img("east", rc->mlx));
    }
}


void draw_tex(t_ctx *rc, int x)
{
    int y;
    int tex_y;
    int pixel;
    int color;
    
    y = rc->slice.draw_start - 1;
    while (++y < rc->slice.draw_end)
    {
        tex_y = (int)rc->slice.tex_pos & (rc->cfg.h - 1);
        rc->slice.tex_pos += rc->slice.tex_step;
        color = *(int*)(rc->frame.addr + (tex_y * rc->frame.line_len + rc->slice.tex_x * (rc->frame.bpp / 8)));
        pixel = (y * rc->frame.line_len) + (x * (rc->frame.bpp / 8));
        *(unsigned int *)(rc->frame.addr + pixel) = color;
    }
}
//busca la textura segun corresponda