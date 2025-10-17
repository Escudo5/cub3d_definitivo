/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escudo5 <escudo5@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:32:25 by escudo5           #+#    #+#             */
/*   Updated: 2025/10/17 16:29:39 by escudo5          ###   ########.fr       */
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
