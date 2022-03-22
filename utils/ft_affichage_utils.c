/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:14:02 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 11:17:02 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_struct *st)
{
	write(1, &c, 1);
	st->return_value = st->return_value + 1;
}

void	ft_putstr(char *str, t_struct *st)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], st);
		i++;
	}
}

void	ft_putnbr(int nb, t_struct *st)
{
	if (nb == -2147483648)
	{
		ft_putstr("2147483648", st);
		return ;
	}
	if (nb < 0)
		nb = nb * -1;
	if (nb > 9)
		ft_putnbr(nb / 10, st);
	ft_putchar((nb % 10) + '0', st);
}

void	ft_putunbr(unsigned int nb, t_struct *st)
{
	if (nb > 9)
		ft_putunbr(nb / 10, st);
	ft_putchar((nb % 10) + '0', st);
}
