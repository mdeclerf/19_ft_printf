/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:45:11 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:26 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ad_1(char *return_char, t_struct *st)
{
	if ((st->W != 0 && st->zero == 1) || (st->dot == 1 && st->P != 0))
	{
		return_char[0] = '\0';
		st->vaPnull = 1;
		return (return_char);
	}
	else
	{
		return_char[0] = '0';
		return_char[1] = 'x';
		return_char[2] = '0';
		return_char[3] = '\0';
		st->vaPnull = 1;
		return (return_char);
	}
}

int	ft_ad_2(int temp)
{
	if (temp < 10)
		temp = temp + '0';
	else
		temp = temp + 'a' - 10;
	return (temp);
}

char	*ft_ad_3(char *return_char)
{
	return_char[0] = '0';
	return_char[1] = 'x';
	return (return_char);
}

char	*ft_ad(unsigned long long int nb, t_struct *st)
{
	static char	hexnum[20];
	static char	return_char[20];
	int			i;
	int			j;
	int			temp;

	i = 0;
	j = 2;
	if (nb == 0)
		return (ft_ad_1(return_char, st));
	while (nb != 0)
	{
		temp = nb % 16;
		hexnum[i++] = ft_ad_2(temp);
		nb = nb / 16;
	}
	i = i - 1;
	if ((st->W != 0 && st->zero == 1) || st->P != 0
		|| (st->P != 0 && st->zero == 1))
		j = 0;
	ft_ad_3(return_char);
	while (i >= 0)
		return_char[j++] = hexnum[i--];
	return_char[j] = '\0';
	return (return_char);
}
