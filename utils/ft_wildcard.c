/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:23:14 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:18:00 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_wildcard(va_list listarg, t_struct *st)
{
	if (st->star == 1 && st->dot == 0)
		st->W = va_arg(listarg, int);
	if (st->star == 1 && st->dot == 1)
	{
		if (st->P != 0 || st->prec0 == 1 || st->starp == 0)
			st->W = va_arg(listarg, int);
		else
			st->P = va_arg(listarg, int);
	}
	if (st->star == 2 && st->dot == 1)
	{
		st->W = va_arg(listarg, int);
		st->P = va_arg(listarg, int);
	}
	if (st->W < 0)
	{
		st->W = st->W * -1;
		st->score = 1;
		st->zero = 0;
	}
}
