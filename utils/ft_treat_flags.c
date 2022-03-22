/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:20:05 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:53 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flags_handling(t_struct *st, const char *format, int i)
{
	if (format[i] == 'u')
		ft_u(st);
	if (format[i] == 'c')
		ft_c(st);
	else if (format[i] == 'i' || format[i] == 'd')
		ft_i(st);
	else if (format[i] == 's')
		ft_s(st);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_x(st);
	else if (format[i] == 'p')
		ft_p(st);
	else if (format[i] == '%')
		ft_pourcent(st);
}

void	ft_back_display(t_struct *st, const char *format, int i)
{
	if (format[i] == 'u')
		ft_back_display_u(st);
	if (format[i] == 'c')
		ft_back_display_c(st);
	else if (format[i] == 'i' || format[i] == 'd')
		ft_back_display_i(st);
	else if (format[i] == 's')
		ft_back_display_s(st);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_back_display_x(st);
	else if (format[i] == 'p')
		ft_back_display_p(st);
	else if (format[i] == '%')
		ft_back_display_pourcent(st);
}
