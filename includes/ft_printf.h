/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:58:54 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/06/14 12:42:57 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				return_value;
	int				va_len;
	int				free;
	int				W;
	int				P;
	int				prec0;
	int				star;
	int				starp;
	int				score;
	int				zero;
	int				dot;
	int				vaI;
	int				vaI0;
	int				sign;
	int				minus;
	unsigned int	vaU;
	int				vaU0;
	char			*vaS;
	int				vaSnull;
	int				vaC;
	void			*vaP;
	int				vaPnull;
	char			*vaX;
	int				vaX0;
	int				vaPourcent;
}					t_struct;

/*
** printf (ft_printf.c)
*/
int		ft_printf(const char *format, ...);
int		ft_printf_bis(const char *format, int i, t_struct *st, va_list listarg);

/*
** functions from the libft (ft_strlen.c ft_atoi.c)
*/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);

/*
** functions to initialize and reset the struct (ft_structure_init.c)
*/
void	ft_struct_init(t_struct *structure);
void	ft_flags_reset(t_struct *st);
void	ft_flags_reset_2(t_struct *st);

/*
** functions to fill the struct with flags 
** (ft_structure_flags.c ft_structure_flags_utils.c)
*/
int		ft_struct_fill_flags(const char *format, int i, t_struct *st);
char	*ft_wp_storage(int i, const char *format);
int		ft_width(const char *format, int i, t_struct *st);
int		ft_precision(const char *format, int i, t_struct *st);
int		ft_star(const char *format, int i, t_struct *st);
int		ft_dot(int i, t_struct *st);
int		ft_score(int i, t_struct *st);

/*
** functions to fill the struct with va_args (also converts p and x in str)
** (ft_va_storage.c ft_wildcard.c ft_putaddress.c ft_puthex.c )
*/
void	ft_arg_sto(int i, va_list listarg, const char *format, t_struct *st);
void	ft_wildcard(va_list listarg, t_struct *st);
char	*ft_hex_1(t_struct *st, char	*return_char);
int		ft_hex_2(const char *format, int index, int temp);
char	*ft_hex(unsigned int nb, const char *format, int index, t_struct *st);
char	*ft_ad_1(char *return_char, t_struct *st);
int		ft_ad_2(int temp);
char	*ft_ad_3(char *return_char);
char	*ft_ad(unsigned long long int nb, t_struct *st);
void	ft_arg_sto_i( va_list listarg, t_struct *st);
void	ft_arg_ucs(int i, va_list listarg, t_struct *st, const char *format);
void	ft_arg_sto_x( int i, va_list listarg, t_struct *st, const char *format);

/*
** functions to count and store the length of what needs to be printed
** (ft_va_len.c)
*/
int		ft_va_len (int i, const char *format, t_struct *st);
int		ft_countnbr(int nb);
int		ft_countunbr(unsigned int nb);

/*
** functions to handle the flags 
** (ft_treat_flags.c ft_flags_c.c ft_flags_i.c ft_flags_p.c
** ft_flags_pourcent.c ft_flags_s.c ft_flags_u.c ft_flags_x.c)
*/
void	ft_flags_handling(t_struct *st, const char *format, int i);
void	ft_i_1(t_struct *st, int j);
void	ft_i_2(t_struct *st, int j);
void	ft_i_3(t_struct *st, int j);
void	ft_i(t_struct *st);
void	ft_u_1(t_struct *st, int j);
void	ft_u_2(t_struct *st, int j);
void	ft_u_3(t_struct *st, int j);
void	ft_u(t_struct *st);
void	ft_s_1(t_struct *st, char *in_struct, char *replacement);
void	ft_s_2(t_struct *st, int j);
void	ft_s_3(t_struct *st, int j);
void	ft_s(t_struct *st);
void	ft_p_1(t_struct *st, int j);
void	ft_p_2(t_struct *st, int j);
void	ft_p_3(t_struct *st, int j);
void	ft_p(t_struct *st);
void	ft_x_1(t_struct *st, int j);
void	ft_x_2(t_struct *st, int j);
void	ft_x_3(t_struct *st, int j);
void	ft_x(t_struct *st);
void	ft_c(t_struct *st);
void	ft_pourcent(t_struct *st);

/*
** display functions
** (ft_affichage.c ft_affichage_utils.c)
*/
void	ft_affichage(const char *format, t_struct *st, int i);
void	ft_putchar(char c, t_struct *st);
void	ft_putstr(char *str, t_struct *st);
void	ft_putnbr(int nb, t_struct *st);
void	ft_putunbr(unsigned int nb, t_struct *st);
void	ft_affichage_i(t_struct *st);
void	ft_affichage_u(t_struct *st);

/*
** functions to handle the - flag
** (ft_treat_flags.c ft_flags_c.c ft_flags_i.c ft_flags_pourcent.c 
** ft_flags_s_back.c ft_flags_u_back.c ft_flags_x.c ft_flags_p_back)
*/
void	ft_back_display(t_struct *st, const char *format, int i);
int		ft_back_display_u_1(t_struct *st, int j);
void	ft_back_display_u(t_struct *st);
void	ft_back_display_c(t_struct *st);
void	ft_back_display_i(t_struct *st);
int		ft_back_display_s_1(t_struct *st, int j);
void	ft_back_display_s(t_struct *st);
void	ft_back_display_x(t_struct *st);
void	ft_back_display_p_1(t_struct *st, int j);
void	ft_back_display_p(t_struct *st);
void	ft_back_display_pourcent(t_struct *st);

#endif