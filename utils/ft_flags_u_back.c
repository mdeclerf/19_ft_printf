/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_u_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:02:25 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:19 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_back_display_u_1(t_struct *st, int j)
{
	if (st->P < st->va_len && st->vaU0 == 0)
		j = st->W - st->va_len;
	else if (st->P < 1)
	{
		if (st->vaU0 == 1)
		{
			j = st->W;
			if (st->P != 0)
				j --;
		}
		else
			j = 0;
	}
	else
		j = st->W - st->P;
	return (j);
}

void	ft_back_display_u(t_struct *st)
{
	int	j;

	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len;
		if (st->dot == 1 && (st->vaU != 0 || st->vaU0 == 1))
			j = ft_back_display_u_1(st, j);
		if (st->dot == 1 && st->vaU0 == 1 && st->prec0 == 1)
			j = st->W;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
