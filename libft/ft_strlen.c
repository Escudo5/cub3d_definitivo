/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:05:34 by acastrov          #+#    #+#             */
/*   Updated: 2025/02/09 16:18:31 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Returns size of str via counting number of chars without \0
size_t	ft_strlen(const char *s)
{
	size_t	string_size;

	if (!s)
		return (0);
	string_size = 0;
	while (s[string_size] != '\0')
		string_size++;
	return (string_size);
}
