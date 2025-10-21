/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:41:52 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/09 16:10:50 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Copies a const string on a new string with malloc
char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	sl;

	if (!s)
		return (NULL);
	sl = ft_strlen(s) + 1;
	new_string = malloc(sl);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s, sl);
	return (new_string);
}
