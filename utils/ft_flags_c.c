/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:51:46 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:08 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_c(t_struct *st)
{
	int	j;

	if (st->zero == 1 && st->W != 0 )
	{
		j = st->W - st->va_len;
		while (j > 0)
		{
			ft_putchar('0', st);
			j --;
		}
	}
	if (st->W != 0 && st->score == 0 && st->zero == 0)
	{
		j = st->W - st->va_len;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}

void	ft_back_display_c(t_struct *st)
{
	int	j;

	if (st->score == 1 && st->W != 0)
	{
		j = st->W - st->va_len;
		while (j > 0)
		{
			ft_putchar(' ', st);
			j --;
		}
	}
}
