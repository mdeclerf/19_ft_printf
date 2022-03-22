/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:01:10 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 12:39:24 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_s_1(t_struct *st, char *in_struct, char *replacement)
{
	int	count;

	count = st->P;
	in_struct = st->vaS;
	replacement = malloc(sizeof(char) * (count + 1));
	if (replacement == NULL)
		return ;
	replacement[count] = '\0';
	count --;
	while (count >= 0)
	{
		replacement[count] = in_struct[count];
		count --;
	}
	st->vaS = replacement;
	st->free = 1;
}

void	ft_s_2(t_struct *st, int j)
{
	j = st->W - st->va_len;
	while (j > 0)
	{
		ft_putchar('0', st);
		j --;
	}
}

void	ft_s_3(t_struct *st, int j)
{
	j = st->W - st->va_len;
	if (st->dot == 1 && st->P == 0)
		j = j + st->va_len;
	if (st->dot == 1 && st->P < st->va_len)
		j = st->W - st->P;
	if (st->P < 0)
		j = st->W - st->va_len;
	while (j > 0)
	{
		ft_putchar(' ', st);
		j --;
	}
}

void	ft_s(t_struct *st)
{
	char	*in_struct;
	char	*replacement;
	int		j;

	j = 0;
	in_struct = NULL;
	replacement = NULL;
	if (st->P > 0 || st->prec0 == 1 || (st->dot == 1 && st->P == 0))
		ft_s_1(st, in_struct, replacement);
	if (st->zero == 1 && st->W != 0)
		ft_s_2(st, j);
	if (st->W != 0 && st->score == 0 && st->zero == 0)
		ft_s_3(st, j);
}
