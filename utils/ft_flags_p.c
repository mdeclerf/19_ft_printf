/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:57:02 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 14:01:42 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_p_1(t_struct *st, int j)
{
	j = st->W - st->va_len;
	if (st->dot == 1 && st->P == 0 && st->vaPnull == 1)
		j++;
	if (st->dot == 1 && st->P > st->va_len)
		j = j - (st->P - st->va_len - 2);
	if (st->dot == 1 && st->P != 0)
		j = j - 2;
	while (j > 0)
	{
		ft_putchar(' ', st);
		j --;
	}	
}

void	ft_p_2(t_struct *st, int j)
{
	j = st->W - st->va_len - 2;
	if (st->vaPnull == 1 && st->W <= 2)
		j = 1;
	ft_putstr("0x", st);
	while (j > 0)
	{
		ft_putchar('0', st);
		j--;
	}
}

void	ft_p_3(t_struct *st, int j)
{
	j = st->P - st->va_len;
	ft_putstr("0x", st);
	if (st->vaPnull == 1)
		j = j - 4;
	while (j > 0)
	{
		ft_putchar('0', st);
		j--;
	}
}

void	ft_p(t_struct *st)
{
	int	j;

	j = 0;
	if (st->W != 0 && st->score == 0 && st->zero == 0)
		ft_p_1(st, j);
	if (st->zero == 1 && st->W != 0)
		ft_p_2(st, j);
	if (st->dot == 1 && st->P != 0 && st->zero == 0)
		ft_p_3(st, j);
	if (st->dot == 1 && st->P != 0 && st->zero == 1)
	{
		j = st->P - st->va_len;
		if (st->vaPnull == 1)
			j = j - 4;
		ft_putstr("0x", st);
		while (j > 0)
		{
			ft_putchar('0', st);
			j--;
		}
	}
	if (st->dot == 1 && st->P == 0 && st->vaPnull == 1)
		st->vaP = "0x";
}
