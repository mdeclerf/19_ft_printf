/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:48:22 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:51 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_struct_init(t_struct *st)
{
	st->return_value = 0;
	st->W = 0;
	st->P = 0;
	st->star = 0 ;
	st->starp = 0 ;
	st->score = 0;
	st->zero = 0;
	st->dot = 0;
	st->va_len = 0;
	st->sign = 0 ;
	st->vaI = 0;
	st->vaI0 = 0;
	st->vaU = 0;
	st->vaS = NULL;
	st->free = 0;
	st->vaC = 0;
	st->vaP = NULL;
	st->vaPnull = 0;
	st->vaSnull = 0;
	st->vaX = 0;
	st->prec0 = 0;
	st->minus = 0;
	st->vaU0 = 0;
	st->vaX0 = 0;
	st->vaPourcent = 0;
}

void	ft_flags_reset_2(t_struct *st)
{
	st->vaU = 0;
	st->vaS = NULL;
	st->free = 0;
	st->vaC = 0;
	st->vaP = NULL;
	st->vaPnull = 0;
	st->vaSnull = 0;
	st->vaX = 0;
	st->prec0 = 0;
	st->minus = 0;
	st->vaU0 = 0;
	st->vaX0 = 0;
	st->vaPourcent = 0;
}

void	ft_flags_reset(t_struct *st)
{
	if (st->free == 1)
		free(st->vaS);
	st->W = 0;
	st->P = 0;
	st->star = 0 ;
	st->starp = 0 ;
	st->score = 0;
	st->zero = 0;
	st->dot = 0;
	st->va_len = 0;
	st->sign = 0 ;
	st->vaI = 0;
	st->vaI0 = 0;
	ft_flags_reset_2(st);
}
