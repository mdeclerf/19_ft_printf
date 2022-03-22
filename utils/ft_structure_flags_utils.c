/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_flags_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:12:53 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:43 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_width(const char *format, int i, t_struct *st)
{
	char	*temp;

	temp = ft_wp_storage(i, format);
	st->W = ft_atoi(temp);
	i = i + ft_strlen(temp);
	free(temp);
	return (i);
}

int	ft_precision(const char *format, int i, t_struct *st)
{
	char	*temp;

	temp = ft_wp_storage(i, format);
	st->P = ft_atoi(temp);
	if (st->P == 0)
		st->prec0 = 1;
	i = i + ft_strlen(temp);
	free(temp);
	return (i);
}

int	ft_star(const char *format, int i, t_struct *st)
{
	if (format[i - 1] == '.')
	{
		st->starp ++;
		st->star++;
	}
	else
		st->star++;
	i++;
	return (i);
}

int	ft_dot(int i, t_struct *st)
{
	st->dot = 1;
	i++;
	return (i);
}

int	ft_score(int i, t_struct *st)
{
	st->score = 1;
	i++;
	return (i);
}
