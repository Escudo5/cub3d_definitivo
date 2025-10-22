/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:48:01 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/22 18:59:52 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parser_extension(char *filename, int *map_fd)
{
	char	*find;

	find = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (!find)
	{
		ft_putstr_fd("Invalid '.cub' extension", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	if (find != ft_strrchr(filename, '.'))
	{
		ft_putstr_fd("Invalid '.cub' extension", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	*map_fd = open(filename, O_RDONLY);
	if (*map_fd < 0)
	{
		perror("Can't open map");
		return (INPUT_ERROR);
	}
	return (SUCCESS);
}

int	store_imgs(t_ctx *cube, int *map_fd, char *filename)
{
	if (get_NO(cube, map_fd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_SO(cube, map_fd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_WE(cube, map_fd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_EA(cube, map_fd) != SUCCESS)
		return (INPUT_ERROR);
	gnl_cleanup(*map_fd);
	ft_putstr_fd("All ok\n",2);
	close(*map_fd);
	return (SUCCESS);
}

// int	parser_clean_map(char *filename, t_map *map)
// {
// 	int		map_fd;
// 	char	*temp;

// 	map_fd = open(filename, O_RDONLY);
// 	temp = ft_strtrim(get_next_line(map_fd));
// 	if (temp == NULL){
// 		close(map_fd);
// 		return (INPUT_ERROR);
// 	}
// 	map->height = 1;
// 	map->width = ft_strlen(temp);
// 	while (temp)
// }

int	parser(char *argv, t_ctx *cube)
{
	int		map_fd;

	if (parser_extension(argv, &map_fd) != SUCCESS)
		return (INPUT_ERROR);
	if (store_imgs(cube, &map_fd, argv) != SUCCESS)
		return (INPUT_ERROR);
	// map = malloc(sizeof(t_map));
	// if (!map)
	// 	return (MALLOC_ERROR);
	// if (parser_store_map(argv[1], &map) != SUCCESS)
	// {
	// 	free(map);
	// 	return (INPUT_ERROR);
	// }
	// cube->map = map;
	close(map_fd);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_ctx	*cube;
	
	if (argc != 2 || !argv[1])
	{
		ft_printf("Incorrect number of arguments\n");
		return (SUCCESS);
	}
	cube = ft_calloc(1, sizeof(t_ctx));
	if (!cube)
		return (MALLOC_ERROR);
	if (parser(argv[1], cube) != SUCCESS)
	{
		free(cube);
		return (INPUT_ERROR);
	}
	// free(cube->map);
	free(cube->tex_north.addr);
	free(cube->tex_south.addr);
	free(cube->tex_west.addr);
	free(cube->tex_east.addr);
	free(cube);
	return (SUCCESS);
}
