/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:56 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:24 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_x_1(t_struct *st, int j)
{
	j = st->W - st->va_len;
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_x_2(t_struct *st, int j)
{
	j = st->W - st->P;
	if (st->P == 1)
		j++;
	if (st->P <= st->va_len)
		j = st->W - st->va_len;
	if (st->P == 0 && st->vaX0 == 1 && st->dot == 1)
		j ++;
	if (st->P < 0 && st->zero == 1)
		j = 0;
	while (j > 0)
	{
		ft_putchar(' ', st);
		j --;
	}
}

void	ft_x_3(t_struct *st, int j)
{
	j = st->P - st->va_len;
	if (st->P < 0 && st->zero == 0)
		j = 0;
	if (st->P < 0 && st->zero == 1)
		j = st->W - st->va_len;
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_x(t_struct *st)
{
	int	j;

	j = 0;
	if (st->zero == 1 && st->score == 1)
		st->zero = 0;
	if (st->zero == 1 && st->dot == 0)
		ft_x_1(st, j);
	if (st->W != 0 && st->score == 0 && (st->zero == 0 || st->dot == 1))
		ft_x_2(st, j);
	if (st->dot == 1)
		ft_x_3(st, j);
}

void	ft_back_display_x(t_struct *st)
{
	int	j;

	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len;
		if (st->dot == 1 && (st->vaX != 0 || st->vaX0 == 1))
		{
			if (st->P < st->va_len && st->vaX0 == 0)
				j = st->W - st->va_len;
			else
				j = st->W - st->P;
		}
		if (st->dot == 1 && st->vaX0 == 1 && st->prec0 == 1)
			j = st->W;
		if (st->dot == 1 && st->vaX0 == 1 && st->P < 0)
			j = st->W - st->va_len;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
