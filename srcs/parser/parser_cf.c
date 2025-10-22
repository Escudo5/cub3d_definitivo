/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:09:40 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/22 21:48:21 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parse_line(char *temp, int *colors, char *set)
{
	char	*start;
	int		i;

	if (ft_strncmp(temp, set, 2) || !ft_strchr(temp, ','))
		return (INPUT_ERROR);
	temp += 2;
	i = 0;
	while (i < 3)
	{
		while (*temp && !ft_isdigit(*temp))
			temp++;
		start = temp;
		while (ft_isdigit(*temp))
			temp++;
		colors[i] = ft_atoi(start);
		if (colors[i] < 0 || colors[i] > 255)
			return (INPUT_ERROR);
		if (i < 2)
		{
			if (*temp++ != ',')
				return (INPUT_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	get_f(t_ctx *cube, int *mapfd)
{
	char	*temp;
	char	*temp_color;
	int		i;
	int		colors[3];

	i = 0;
	while (i++ < 2)
	{
		temp = get_next_line(*mapfd);
		if (temp == NULL)
			return (exit_parser(NULL, mapfd, "Invalid F\n", INPUT_ERROR));
		if (i == 1)
			free(temp);
	}
	ft_printf("%s\n", temp);
	if (parse_line(temp, colors, "F ") != SUCCESS)
		return (exit_parser(temp, mapfd, "Invalid F\n", INPUT_ERROR));
	cube->cfg.floor_color.r = colors[0];
	cube->cfg.floor_color.g = colors[1];
	cube->cfg.floor_color.b = colors[2];
	ft_printf("F Red: %d\n", cube->cfg.floor_color.r);
	ft_printf("F Green: %d\n", cube->cfg.floor_color.g);
	ft_printf("F Blue: %d\n", cube->cfg.floor_color.b);
	free(temp);
	return (SUCCESS);
}

int	get_c(t_ctx *cube, int *mapfd)
{
	char	*temp;
	char	*temp_color;
	int		i;
	int		colors[3];

	i = 0;
	temp = get_next_line(*mapfd);
	if (temp == NULL)
		return (exit_parser(NULL, mapfd, "Invalid C\n", INPUT_ERROR));
	ft_printf("%s\n", temp);
	if (parse_line(temp, colors, "C ") != SUCCESS)
		return (exit_parser(temp, mapfd, "Invalid C\n", INPUT_ERROR));
	cube->cfg.ceil_color.r = colors[0];
	cube->cfg.ceil_color.g = colors[1];
	cube->cfg.ceil_color.b = colors[2];
	ft_printf("C Red: %d\n", cube->cfg.ceil_color.r);
	ft_printf("C Green: %d\n", cube->cfg.ceil_color.g);
	ft_printf("C Blue: %d\n", cube->cfg.ceil_color.b);
	free(temp);
	return (SUCCESS);
}
