/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:56:03 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:10 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_i_1(t_struct *st, int j)
{
	j = st->W - st->va_len;
	if (st->sign == 1)
	{
		st->minus = 1;
		j--;
		ft_putchar('-', st);
	}
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_i_2(t_struct *st, int j)
{
	j = st->W - st->P - st->sign;
	if (st->dot == 1)
		j = st->W - st->P - st->sign - st->prec0;
	if (st->P <= st->va_len)
	{
		j = st->W - st->va_len - st->sign;
		if (st->prec0 == 1 && st->vaI0 == 1)
			j ++;
	}
	if (st->dot == 1 && st->vaI0 == 1 && st->prec0 == 0 && st->P == 0)
		j = st->W;
	if (st->P < 0 && st->zero == 0)
		j = st->W - st->va_len - st->sign;
	if (st->P < 0 && st->zero == 1)
		j = 0;
	while (j > 0)
	{
		ft_putchar(' ', st);
		j --;
	}
	if (st->sign == 1 && st->dot == 0)
	{
		st->minus = 1;
		ft_putchar('-', st);
	}
}

void	ft_i_3(t_struct *st, int j)
{
	j = st->P - st->va_len;
	if (st->P < 0 && st->zero == 0)
		j = 0;
	if (st->P < 0 && st->zero == 1)
		j = st->W - st->va_len - st->sign;
	if (st->sign == 1)
	{
		st->minus = 1;
		ft_putchar('-', st);
	}
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_i(t_struct *st)
{
	int	j;

	j = 0;
	if (st->zero == 1 && st->score == 1)
		st->zero = 0;
	if (st->zero == 1 && st->dot == 0)
		ft_i_1(st, j);
	if (st->W != 0 && st->score == 0 && (st->zero == 0 || st->dot == 1))
		ft_i_2(st, j);
	if (st->dot == 1)
		ft_i_3(st, j);
	if (st->sign == 1 && st->minus == 0)
		ft_putchar('-', st);
}

void	ft_back_display_i(t_struct *st)
{
	int	j;

	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len - st->sign;
		if (st->dot == 1 && (st->vaI != 0 || st->vaI0 == 1))
		{
			if (st->P < st->va_len && st->vaI0 == 0)
				j = st->W - st->va_len - st->sign;
			else
				j = st->W - st->P - st->sign;
		}
		if (st->dot == 1 && st->vaI0 == 1 && st->prec0 == 1)
			j = st->W;
		if (st->dot == 1 && st->vaI0 == 1 && st->P < 0)
			j = st->W - st->va_len;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
