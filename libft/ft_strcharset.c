/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:58:07 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/23 18:59:46 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcharset(const char *s, const char *charset)
{
	size_t	i;
	size_t	j;
	int		found;

	if (!s || !charset)
		return (0);
	i = 0;
	while (s[i])
	{
		found = 0;
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}
