/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:32:28 by escudo5           #+#    #+#             */
/*   Updated: 2025/10/17 16:36:45 by escudo5          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel(t_ctx *rc, int x , int y, uint32_t color)
{
    char *dst;
    if (!rc || !rc->frame.addr)
        return;
    dst = rc->frame.addr + (y * rc->frame.line_len + x * (rc->frame.bpp / 8));
    *(unsigned int *)dst = color;
}

unsigned int  draw_vline(t_ctx *rc, int x, int y)
{
    char *dst;
    dst = rc->frame.addr + (y * rc->frame.line_len + x * (rc->frame.bpp/ 8));
    return(*(unsigned int *)dst);
}



void draw_background(t_ctx *rc, int c)
{
    int x;
    int y;
    y = -1;
    while (++y < rc->vec2.y)
    {
        x = -1;
        while (++x < rc->vec2.x)
            put_pixel(rc, rc->vec2.x, rc->vec2.y, c);
    }
}
//rellena un rectangulo, no es muy eficiente pero funciona.

void draw_env(t_ctx *rc, int start_y, int end_y)
{
    int x;
    int y;
    int px;
    t_color color;

    y = start_y - 1;
    if (start_y < rc->cfg.h / 2)
        color = rc->cfg.ceil_color;
    else
        color = rc->cfg.floor_color;
    while (++y < end_y)
    {
        x = -1;
        while (++x < rc->cfg.w)
        {
            px = y * rc->frame.line_len + x * rc->frame.bpp / 8;
            *(unsigned int *)(rc->frame.addr + px) = set_color(color);
        }
    }
}


void draw_mix(t_ctx *rc)
{
    draw_env(rc, 0, rc->cfg.h / 2);
    draw_env(rc, rc->cfg.h / 2, rc->cfg.h);
}

//dibuja techo o suelo