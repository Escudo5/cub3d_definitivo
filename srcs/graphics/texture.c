/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:53:26 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/21 13:55:41 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

t_img *search_img(char *direction, t_ctx *rc)
{
    if (direction[0] == 'n')
        return (&rc->tex_north);
    else if (direction[0] == 's')
        return (&rc->tex_south);
    else if (direction[0] == 'e')
        return (&rc->tex_east);
    else if (direction[0] == 'w')
        return (&rc->tex_west);
    return (NULL);
}

t_img *get_wall_text(t_ctx *rc)  // ← Devuelve t_img*, no t_ctx*
{
    if (rc->ray.side == 0)
    {
        if (rc->ray.ray_dir.x > 0)
            return (search_img("east", rc));  // ← Pasa rc, no rc->mlx
        else
            return (search_img("west", rc));
    }
    else
    {
        if (rc->ray.ray_dir.y > 0)
            return (search_img("south", rc));
        else
            return (search_img("north", rc));
    }
}

void draw_tex(t_ctx *rc, int x)
{
    int y;
    int tex_y;
    int pixel;
    int color;
    t_img *texture;
    
    texture = get_wall_text(rc);
    if (!texture || !texture->ptr)
        return;
    
    y = rc->slice.draw_start - 1;
    while (++y < rc->slice.draw_end)
    {
        tex_y = (int)rc->slice.tex_pos & (texture->h - 1);
        rc->slice.tex_pos += rc->slice.tex_step;
        color = *(int *)(texture->addr + 
            (tex_y * texture->line_len + rc->slice.tex_x * (texture->bpp / 8)));
        pixel = (y * rc->frame.line_len) + (x * (rc->frame.bpp / 8));
        *(unsigned int *)(rc->frame.addr + pixel) = color;
    }
}
