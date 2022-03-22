/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:50:32 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:06 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (0);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	return_value;

	i = 0;
	sign = 1;
	return_value = 0;
	while (*str != '\0' && ft_isspace(*str) == 0)
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((i >= 18 || return_value > 1ull << 63) && sign == 1)
			return (-1);
		if ((i >= 18 || return_value > 1ull << 63) && sign == -1)
			return (0);
		return_value = (return_value * 10) + (str[i] - '0');
		i++;
	}
	return (return_value * sign);
}
