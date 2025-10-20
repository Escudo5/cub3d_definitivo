/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:25 by acastrov          #+#    #+#             */
/*   Updated: 2025/01/20 20:00:46 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Takes a const char, manages spaces and symbols and returns an int
long long int	ft_atoi(const char *nptr)
{
	int			symbol;
	long long	result;

	symbol = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		symbol = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * symbol);
}
