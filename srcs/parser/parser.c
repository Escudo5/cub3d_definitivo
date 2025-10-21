/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:48:01 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/21 20:59:46 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parser_extension(char *filename)
{
	char	*find;
	int		map_fd;

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
	map_fd = open(filename, O_RDONLY);
	if (map_fd < 0)
	{
		perror("Can't open map");
		return (INPUT_ERROR);
	}
	close (map_fd);
	return (SUCCESS);
}

int	store_imgs(t_ctx *cube, int *map_fd, char *filename)
{
	char	*temp;

	*map_fd = open(filename, O_RDONLY);
	temp = get_next_line(*map_fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(*map_fd);
	}
	// if (temp == NULL)
	// {
	// 	close(*map_fd);
	// 	return (INPUT_ERROR);
	// }
	// if (!ft_strncmp(temp, "NO", 2))
	// {
	// 	ft_putstr_fd("Invalid 'NO' img\n", STDERR_FILENO);
	// 	free(temp);
	// 	close(*map_fd);
	// 	return (INPUT_ERROR);
	// }
	free(temp);
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

int	parser(char **argv, t_ctx *cube)
{
	int		map_fd;

	if (parser_extension(argv[1]) != SUCCESS)
		return (INPUT_ERROR);
	if (store_imgs(cube, &map_fd, argv[1]) != SUCCESS)
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
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_ctx	*cube;
	
	if (argc != 2 || !*argv)
	{
		ft_printf("Incorrect number of arguments\n");
		return (SUCCESS);
	}
	cube = malloc(sizeof(t_ctx));
	if (!cube)
		return (MALLOC_ERROR);
	if (parser(argv, cube) != SUCCESS)
	{
		free(cube);
		return (INPUT_ERROR);
	}
	free(cube->map);
	free(cube);
	return (SUCCESS);
}
