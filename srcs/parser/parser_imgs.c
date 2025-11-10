/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:34:47 by alejandro         #+#    #+#             */
/*   Updated: 2025/11/04 16:11:06 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	get_no(t_ctx *cube, char *temp)
{
	if (!ft_strncmp(temp, "NO", 2))
	{
		if (cube->path.n)
		{
			ft_putstr_fd("More than one NO texture\n", 2);
			return (INPUT_ERROR);
		}
		cube->path.n = ft_strtrim(temp + 2, " \n\t");
		if (!cube->path.n || *cube->path.n == '\0')
		{
			ft_putstr_fd("Invalid texture\n", 2);
			return (INPUT_ERROR);
		}
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	get_so(t_ctx *cube, char *temp)
{
	if (!ft_strncmp(temp, "SO", 2))
	{
		if (cube->path.s)
		{
			ft_putstr_fd("More than one SO texture\n", 2);
			return (INPUT_ERROR);
		}
		cube->path.s = ft_strtrim(temp + 2, " \n\t");
		if (!cube->path.s || *cube->path.s == '\0')
		{
			ft_putstr_fd("Invalid texture\n", 2);
			return (INPUT_ERROR);
		}
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	get_we(t_ctx *cube, char *temp)
{
	if (!ft_strncmp(temp, "WE", 2))
	{
		if (cube->path.w)
		{
			ft_putstr_fd("More than one WE texture\n", 2);
			return (INPUT_ERROR);
		}
		cube->path.w = ft_strtrim(temp + 2, " \n\t");
		if (!cube->path.w || *cube->path.w == '\0')
		{
			ft_putstr_fd("Invalid texture\n", 2);
			return (INPUT_ERROR);
		}
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	get_ea(t_ctx *cube, char *temp)
{
	if (!ft_strncmp(temp, "EA", 2))
	{
		if (cube->path.e)
		{
			ft_putstr_fd("More than one EA texture\n", 2);
			return (INPUT_ERROR);
		}
		cube->path.e = ft_strtrim(temp + 2, " \n\t");
		if (!cube->path.e || *cube->path.e == '\0')
		{
			ft_putstr_fd("Invalid texture\n", 2);
			return (INPUT_ERROR);
		}
		return (SUCCESS);
	}
	return (SUCCESS);
}
