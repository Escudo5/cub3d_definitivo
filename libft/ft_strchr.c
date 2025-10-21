/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:35:27 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/09 15:23:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Locates first char in a string
char	*ft_strchr(const char *s, int c)
{
	char	*c_find_pointer;

	if (!s)
		return (NULL);
	c_find_pointer = (char *)s;
	while (*c_find_pointer)
	{
		if (*c_find_pointer == (char)c)
			return ((char *)c_find_pointer);
		c_find_pointer++;
	}
	if ((char)c == '\0')
		return ((char *)c_find_pointer);
	return (NULL);
}
