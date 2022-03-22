/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:12:53 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:45 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_wp_storage(int i, const char *format)
{
	int		j;
	char	*atoistr;
	int		numcount;

	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		j++;
		i++;
	}
	atoistr = malloc(sizeof(char) * j + 1);
	if (atoistr == NULL)
		return (NULL);
	atoistr[j] = '\0';
	numcount = i - 1;
	while (j > 0)
	{
		atoistr[j - 1] = format[numcount];
		numcount--;
		j--;
	}
	return (atoistr);
}

int	ft_struct_fill_flags(const char *format, int i, t_struct *st)
{
	while (format[i] != 'i' || format[i] != 'd' || format[i] != '%'
		|| format[i] != 's' || format[i] != 'u' || format[i] != 'p'
		|| format[i] != 'x' || format[i] != 'X' || format[i] != 'c')
	{
		if (format[i] == '0' && format[i - 1] == '%')
		{
			st->zero = 1;
			i++;
		}
		else if (format[i] == '-')
			i = ft_score(i, st);
		else if (format[i] == '.')
			i = ft_dot(i, st);
		else if (format[i] == '*')
			i = ft_star(format, i, st);
		else if (format[i] >= '0' && format[i] <= '9' && st->dot == 0)
			i = ft_width(format, i, st);
		else if (format[i] >= '0' && format[i] <= '9' && st->dot == 1)
			i = ft_precision(format, i, st);
		else
			break ;
	}
	return (i);
}
