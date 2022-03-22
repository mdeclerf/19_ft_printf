/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:20:16 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:55 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_countnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (10);
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_countunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_va_len (int i, const char *format, t_struct *st)
{
	int	j;
	int	va_len;

	j = i;
	va_len = 0;
	if (format[j] == 'i' || format[j] == 'd')
		va_len = ft_countnbr(st->vaI);
	else if (format[j] == 'u')
		va_len = ft_countunbr(st->vaU);
	else if (format[j] == 's')
		va_len = ft_strlen(st->vaS);
	else if (format[j] == 'c')
		va_len = 1;
	else if (format[j] == 'p')
		va_len = ft_strlen(st->vaP);
	else if (format[j] == 'x' || format[j] == 'X' )
		va_len = ft_strlen((char *)st->vaX);
	else
		va_len = 0;
	return (va_len);
}
