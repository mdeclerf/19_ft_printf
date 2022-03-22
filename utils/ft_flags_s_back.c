/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_s_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:01:10 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 12:43:07 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_back_display_s_1(t_struct *st, int j)
{
	if (st->P < st->va_len && st->P > 0)
		j = st->W - st->P;
	if (st->P == 0 && st->prec0 == 0)
		j = st->W;
	return (j);
}

void	ft_back_display_s(t_struct *st)
{
	int	j;

	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len;
		if (st->vaSnull == 0 && st->dot == 1)
			j = ft_back_display_s_1(st, j);
		if (st->vaSnull == 1 && st->dot == 1)
		{
			if (st->P < st->va_len && st->P > 0)
				j = st->W - st->P;
			if (st->P == 0 && st->prec0 == 0)
				j = st->W;
		}
		if (st->P == 0 && st->dot == 1)
			j = st->W;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
