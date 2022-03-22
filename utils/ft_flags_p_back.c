/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_p_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:57:02 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:37:44 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_back_display_p_1(t_struct *st, int j)
{
	j = 4;
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_back_display_p(t_struct *st)
{
	int	j;

	j = 0;
	if (st->vaPnull == 1 && st->P != 0)
		ft_back_display_p_1(st, j);
	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len;
		if ((st->vaP != NULL && st->vaPnull == 0) && st->dot == 1)
			j = j - 2;
		if (st->vaPnull == 1 && st->dot == 1)
			j = st->P + st->va_len;
		if (st->dot == 1 && st->P == 0 && st->prec0 == 0)
			j = st->W - st->va_len + st->vaPnull;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
