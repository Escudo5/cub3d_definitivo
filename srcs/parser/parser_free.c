/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:18:28 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/28 18:05:35 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	exit_parser(char *temp, int *fd, char *message, int flag)
{
	ft_putstr_fd(message, 2);
	gnl_cleanup(*fd);
	close(*fd);
	return (flag);
}

int	free_grid(char **grid, char *message, int flag)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (grid[i])
		{
			free (grid[i]);
			i++;
		}
		free(grid);
	}
	ft_putstr_fd(message, STDERR_FILENO);
	return (flag);
}

void	free_paths(t_ctx *cube)
{
	if (cube->path.n)
		free(cube->path.n);
	if (cube->path.s)
		free(cube->path.s);
	if (cube->path.w)
		free(cube->path.w);
	if (cube->path.e)
		free(cube->path.e);
}
