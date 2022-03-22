/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:50:01 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:36 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_hex_1(t_struct *st, char	*return_char)
{
	return_char[0] = '0';
	return_char[1] = '\0';
	st->vaX0 = 1;
	return (return_char);
}

int	ft_hex_2(const char *format, int index, int temp)
{
	if (temp < 10)
		temp = temp + '0';
	else
	{
		if (format[index] == 'x')
			temp = temp + 'a' - 10;
		else if (format[index] == 'X')
			temp = temp + 'A' - 10;
	}
	return (temp);
}

char	*ft_hex(unsigned int nb, const char *format, int index, t_struct *st)
{
	static char	hexnum[20];
	static char	return_char[20];
	int			i;
	int			j;
	int			temp;

	i = 0;
	j = 0;
	if (nb == 0)
		return (ft_hex_1(st, return_char));
	while (nb != 0)
	{
		temp = nb % 16;
		temp = ft_hex_2(format, index, temp);
		hexnum[i] = temp;
		i++;
		nb = nb / 16;
	}
	i --;
	while (i >= 0)
		return_char[j++] = hexnum[i--];
	return_char[j] = '\0';
	return (return_char);
}
