/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:48:01 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/21 19:48:09 by acastrov         ###   ########.fr       */
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

// int	parser_clean_map(char *filename, char **grid);

int	parser(char **argv)
{
	t_map	map;
	char	**grid;

	if (parser_extension(argv[1]) != SUCCESS)
		return (INPUT_ERROR);
	// if (parser_clean_map(argv[1], grid) != SUCCESS)
		// return (INPUT_ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !*argv)
	{
		ft_printf("Incorrect number of arguments\n");
		return (SUCCESS);
	}
	if (parser(argv) != SUCCESS)
		return (INPUT_ERROR);
}
