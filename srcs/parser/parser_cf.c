/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:09:40 by alejandro         #+#    #+#             */
/*   Updated: 2025/11/10 13:26:36 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parse_color(char **temp, int *colors, int i)
{
	char	*start;

	start = *temp;
	while (**temp && ft_isspace(**temp))
		(*temp)++;
	if (**temp == '-' || **temp == '+')
		(*temp)++;
	if (!ft_isdigit(**temp))
		return (INPUT_ERROR);
	while (ft_isdigit(**temp))
		(*temp)++;
	if (**temp && **temp != ',' && !ft_isspace(**temp))
		return (INPUT_ERROR);
	colors[i] = ft_atoi(start);
	if (colors[i] < 0 || colors[i] > 255)
		return (INVALID_COLOR);
	return (SUCCESS);
}

int	parse_line(char *temp, int *colors, char *set)
{
	int		i;
	int		flag;

	if (ft_strncmp(temp, set, 1) || !ft_strchr(temp, ','))
		return (INPUT_ERROR);
	temp += 2;
	i = 0;
	while (i < 3)
	{
		flag = parse_color(&temp, colors, i);
		if (flag == INVALID_COLOR)
			return (INVALID_COLOR);
		else if (flag == INPUT_ERROR)
			return (INPUT_ERROR);
		if (i < 2 && *temp++ != ',')
			return (INPUT_ERROR);
		i++;
	}
	while (*temp)
	{
		if (!ft_isspace(*temp))
			return (INPUT_ERROR);
		temp++;
	}
	return (SUCCESS);
}

int	get_f(t_ctx *cube, char *temp)
{
	int		colors[3];
	int		flag;

	if (*temp != 'F')
		return (SUCCESS);
	if (cube->cfg.floor_color.r)
	{
		ft_putstr_fd("More than one F color\n", 2);
		return (INPUT_ERROR);
	}
	flag = parse_line(temp, colors, "F");
	if (flag == SUCCESS)
		return (flag);
	else
	{
		free (temp);
		return (flag);
	}
}

int	get_c(t_ctx *cube, char *temp)
{
	int		colors[3];
	int		flag;

	if (*temp != 'C')
		return (SUCCESS);
	if (cube->cfg.ceil_color.r)
	{
		ft_putstr_fd("More than one C color\n", 2);
		return (INPUT_ERROR);
	}
	flag = parse_line(temp, colors, "C");
	if (flag == SUCCESS)
		return (flag);
	else
	{
		free (temp);
		return (flag);
	}
}
