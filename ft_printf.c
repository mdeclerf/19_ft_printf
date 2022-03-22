/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:07:43 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/11 14:06:50 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_bis(const char *format, int i, t_struct *st, va_list listarg)
{
	i++;
	i = ft_struct_fill_flags(format, i, st);
	ft_arg_sto(i, listarg, format, st);
	st->va_len = ft_va_len (i, format, st);
	ft_flags_handling(st, format, i);
	ft_affichage(format, st, i);
	ft_back_display(st, format, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		listarg;
	int			len;
	int			i;
	t_struct	temp;
	t_struct	*st;

	i = 0;
	len = ft_strlen(format);
	va_start(listarg, format);
	st = &temp;
	ft_struct_init(st);
	while (i < len)
	{
		if (format[i] == '%')
			i = ft_printf_bis(format, i, st, listarg);
		else
			ft_putchar(format[i], st);
		ft_flags_reset(st);
		i++;
	}
	va_end(listarg);
	return (st->return_value);
}
