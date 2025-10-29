/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:58:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/29 13:19:05 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	store_grid(t_ctx *cube, int	*mapfd, char *temp, char ***map)
{
	int	map_height;

	*map = ft_calloc(MAX_LINES, sizeof(char *));
	if (!*map)
		return (MALLOC_ERROR);
	map_height = 0;
	while (temp)
	{
		if (!ft_strcharset(temp, " 01NSWE\n"))
		{
			ft_putstr_fd("Issue at line ", 2);
			ft_putstr_fd(temp, 2);
			free(temp);
			temp = NULL;
			return (INPUT_ERROR);
		}
		(*map)[map_height++] = ft_strtrim(temp, "\n");
		free(temp);
		temp = NULL;
		temp = get_next_line(*mapfd);
	}
	(*map)[map_height] = NULL;
	cube->map.h = map_height;
	return (SUCCESS);
}

int	fill_gaps(t_ctx *cube, char ***map)
{
	int	flag;
	int	i;
	int	j;

	i = 0;
	while (i < cube->map.h)
	{
		j = 0;
		flag = 0;
		while (j < cube->map.w)
		{
			if (ft_strchr("01NSWE", (*map)[i][j]) && flag == 0)
				flag = 1;
			if (flag == 1 && (*map)[i][j] == ' ' && has_char((*map)[i], j))
				(*map)[i][j] = '0';
			if (flag == 1 && (*map)[i][j] == 'Z')
			{
				(*map)[i][j] = ' ';
				flag = 0;
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_ctx *cube, char **map)
{
	int		y;
	char	*temp;

	y = 0;
	while (y < cube->map.h)
	{
		temp = ft_strtrim(map[y], " ");
		if ((y == 0 || y == cube->map.h - 1)
			&& ft_strcharset(temp, "0NSEW"))
		{
			free(temp);
			return (INPUT_ERROR);
		}
		else
		{
			if (temp[0] != '1' || temp[ft_strlen(temp) - 1] != '1')
			{
				free(temp);
				return (INPUT_ERROR);
			}
		}
		free(temp);
		y++;
	}
	return (SUCCESS);
}

int	get_player_position(t_ctx *cube, char **map)
{
	int	player_count;
	int	x;
	int	y;

	y = 0;
	player_count = 0;
	while (y < cube->map.h)
	{
		x = 0;
		while (x < cube->map.w)
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				player_count++;
				cube->player_start.orientation = map[y][x];
				cube->player_start.y = y;
				cube->player_start.x = x;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (INPUT_ERROR);
	return (SUCCESS);
}

int	store_map(t_ctx *cube, int *mapfd, char *temp)
{
	char	**map;

	if (store_grid(cube, mapfd, temp, &map) != SUCCESS)
		return (free_grid(map, "Invalid symbol\n", INPUT_ERROR));
	if (validate_textures(cube) != SUCCESS)
		return (free_grid(map, "Invalid textures\n", INPUT_ERROR));
	if (normalize_map(cube, &map) != SUCCESS)
		return (free_grid(map, "Invalid map\n", INPUT_ERROR));
	if (fill_gaps(cube, &map) != SUCCESS)
		return (free_grid(map, "Invalid map\n", INPUT_ERROR));
	if (validate_map(cube, map) != SUCCESS)
		return (free_grid(map, "Not closed map\n", INPUT_ERROR));
	if (get_player_position(cube, map) != SUCCESS)
		return (free_grid(map, "Invalid player\n", INPUT_ERROR));
	print_map(map, cube->map.h);
	cube->map.grid = map;
	return(SUCCESS);
	// return (free_grid(map, "Success\n", SUCCESS));
}
