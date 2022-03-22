/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_storage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:23:14 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:40:38 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_arg_sto_i(va_list listarg, t_struct *st)
{
	ft_wildcard(listarg, st);
	st->vaI = va_arg(listarg, int);
	if (st->vaI < 0)
		st->sign = 1;
	if (st->vaI == 0)
		st->vaI0 = 1;
}

void	ft_arg_ucs(int i, va_list listarg, t_struct *st, const char *format)
{
	if (format[i] == 's')
	{
		ft_wildcard(listarg, st);
		st->vaS = va_arg(listarg, char *);
		if (st->vaS == NULL)
		{
			st->vaSnull = 1;
			st->vaS = "(null)";
		}
	}
	else if (format[i] == 'c')
	{
		ft_wildcard(listarg, st);
		st->vaC = va_arg(listarg, int);
	}
	else if (format[i] == 'u')
	{
		ft_wildcard(listarg, st);
		st->vaU = va_arg(listarg, unsigned int);
		if (st->vaU == 0)
			st->vaU0 = 1;
	}
}

void	ft_arg_sto_x(int i, va_list listarg, t_struct *st, const char *format)
{
	ft_wildcard(listarg, st);
	st->vaX = ft_hex(va_arg(listarg, unsigned int), format, i, st);
}

void	ft_arg_sto(int i, va_list listarg, const char *format, t_struct *st)
{
	if (format[i] == 'i' || format[i] == 'd')
		ft_arg_sto_i(listarg, st);
	else if (format[i] == 's' || format[i] == 'c' || format[i] == 'u')
		ft_arg_ucs(i, listarg, st, format);
	else if (format[i] == 'X' || format[i] == 'x')
		ft_arg_sto_x(i, listarg, st, format);
	else if (format[i] == 'p')
	{
		ft_wildcard(listarg, st);
		st->vaP = ft_ad((unsigned long long int)va_arg(listarg, void *), st);
	}
	else if (format[i] == '%')
	{
		ft_wildcard(listarg, st);
		st->vaPourcent = 1;
	}
}
