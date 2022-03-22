/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:02:25 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:22 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_u_1(t_struct *st, int j)
{
	j = st->W - st->va_len;
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_u_2(t_struct *st, int j)
{
	j = st->W - st->P - st->vaU0;
	if (st->P == 1 || st->vaU == 0)
		j++;
	if (st->P <= st->va_len)
	{
		if (st->zero == 1 && st->P < 0)
			j = 0;
		else
			j = st->W - st->va_len + st->prec0;
	}
	if (st->prec0 == 1 && st->vaU != 0)
		j = st->W - st->va_len;
	if (st->dot == 1 && st->prec0 == 0 && st->P == 0)
	{
		if (st->vaU0 == 1)
			j = st->W;
		else
			j = st->W - st->va_len;
	}
	while (j > 0)
	{
		ft_putchar(' ', st);
		j --;
	}
}

void	ft_u_3(t_struct *st, int j)
{
	j = 0;
	if (st->P > 0)
		j = st->P - st->va_len;
	else if (st->P < 0)
	{
		if (st->P < 0 && st->zero == 0)
			j = 0;
		if (st->P < 0 && st->zero == 1)
			j = st->W - st->va_len;
	}
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_u(t_struct *st)
{
	int	j;

	j = 0;
	if (st->zero == 1 && st->score == 1)
		st->zero = 0;
	if (st->zero == 1 && st->dot == 0)
		ft_u_1(st, j);
	if (st->W != 0 && st->score == 0 && (st->zero == 0 || st->dot == 1))
		ft_u_2(st, j);
	if (st->dot == 1 )
		ft_u_3(st, j);
}
