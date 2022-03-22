/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:14:02 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/11 14:17:30 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_affichage_i(t_struct *st)
{
	if (st->vaI == 0)
	{
		if (st->dot == 1 && st->P != 0)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->score == 0)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->zero == 1)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->score == 1)
			ft_putchar('0', st);
	}
	else
		ft_putnbr(st->vaI, st);
}

void	ft_affichage_u(t_struct *st)
{
	if (st->vaU == 0)
	{
		if (st->dot == 1 && st->P != 0)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->score == 0)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->zero == 1)
			ft_putchar('0', st);
		else if (st->dot == 0 && st->score == 1)
			ft_putchar('0', st);
	}
	else
		ft_putunbr(st->vaU, st);
}

void	ft_affichage(const char *format, t_struct *st, int i)
{
	if (format[i] == '%')
		ft_putchar('%', st);
	else if (format[i] == 'i' || format[i] == 'd')
		ft_affichage_i(st);
	else if (format[i] == 's')
		ft_putstr(st->vaS, st);
	else if (format[i] == 'u')
		ft_affichage_u(st);
	else if (format[i] == 'p')
		ft_putstr(st->vaP, st);
	else if (format[i] == 'x' || format[i] == 'X')
	{
		if (st->dot == 1 && st->vaX0 == 1 && st->P == 0)
			ft_putstr(NULL, st);
		else
			ft_putstr((char *)st->vaX, st);
	}
	else if (format[i] == 'c')
		ft_putchar(st->vaC, st);
}
