/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:35:50 by acastrov          #+#    #+#             */
/*   Updated: 2025/07/09 16:09:22 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array);

char	**ft_arraydup(char **argv)
{
	int		i;
	int		j;
	char	**new_array;

	i = 0;
	while (argv[i] != NULL)
		i++;
	new_array = malloc((i + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_array[j] = ft_strdup(argv[j]);
		if (!new_array[j])
		{
			ft_free_array(new_array);
			return (NULL);
		}
		j++;
	}
	new_array[i] = NULL;
	return (new_array);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
