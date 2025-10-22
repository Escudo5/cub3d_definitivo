/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:34:47 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/22 18:58:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	get_NO(t_ctx *cube, int	*map_fd)
{
	char	*temp;

	temp = get_next_line(*map_fd);
	if (temp == NULL)
	{
		ft_putstr_fd("No GNL",2);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	if (ft_strncmp(temp, "NO ", 3))
	{
		ft_putstr_fd("Invalid 'NO' img\n", STDERR_FILENO);
		free(temp);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	cube->tex_north.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n",cube->tex_north.addr);
	return (SUCCESS);
}

int	get_SO(t_ctx *cube, int	*map_fd)
{
	char	*temp;

	temp = get_next_line(*map_fd);
	if (temp == NULL)
	{
		ft_putstr_fd("No GNL",2);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	if (ft_strncmp(temp, "SO ", 3))
	{
		ft_putstr_fd("Invalid 'NO' img\n", STDERR_FILENO);
		free(temp);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	cube->tex_south.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n",cube->tex_south.addr);
	return (SUCCESS);
}

int	get_WE(t_ctx *cube, int	*map_fd)
{
	char	*temp;

	temp = get_next_line(*map_fd);
	if (temp == NULL)
	{
		ft_putstr_fd("No GNL",2);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	if (ft_strncmp(temp, "WE ", 3))
	{
		ft_putstr_fd("Invalid 'NO' img\n", STDERR_FILENO);
		free(temp);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	cube->tex_west.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n",cube->tex_west.addr);
	return (SUCCESS);
}


int	get_EA(t_ctx *cube, int	*map_fd)
{
	char	*temp;

	temp = get_next_line(*map_fd);
	if (temp == NULL)
	{
		ft_putstr_fd("No GNL",2);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	if (ft_strncmp(temp, "EA ", 3))
	{
		ft_putstr_fd("Invalid 'NO' img\n", STDERR_FILENO);
		free(temp);
		gnl_cleanup(*map_fd);
		close(*map_fd);
		return (INPUT_ERROR);
	}
	cube->tex_east.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n",cube->tex_east.addr);
	return (SUCCESS);
}

