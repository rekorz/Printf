/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:24:50 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:24:53 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct			s_struct
{
	char				*string;
	int					nprinted;
	int					saida;
	int					i;
	int					len;
	int					integer;
	unsigned int		unsig;
	unsigned long int	uli;
	int					width;
	int					minus;
	int					zero;
	int					precision;
	int					precisionft;
	int					ast;
	int					astft;
	int					ifpoint;
}						t_struct;
/*
** van las funciones que use
*/
int						ft_printf(const char *str, ...);
void					putcha(const char *str, t_struct *f);
void					putstr(char *s, t_struct *f);
void					print_space(int j, t_struct *f);
int						print_zero(int j, t_struct *f);
size_t					ft_strlen(const char *s);
char					*ft_itoa(int nbr);
void					ft_flags(const char *str, t_struct *f, va_list ap);
char					*ft_utoa(unsigned int n);
char					*ft_utoa_cap(unsigned int nbr);
char					*ft_uitoa(unsigned long int nbr);
char					*ft_utoa_uns(unsigned int nbr);
char					*ft_strdup(const char *s1);
char					*ft_uitoa_ret(size_t len, char *str);
void					restart(t_struct *f);
void					convers(const char *str, t_struct *f, va_list ap);
void					ifchar(const char *str, t_struct *f, va_list ap);
void					ifstring(const char *str, t_struct *f, va_list ap);
void					ifpointer(const char *str, t_struct *f, va_list ap);
void					ifinteger(const char *str, t_struct *f, va_list ap);
void					ifunsigned(const char *str, t_struct *f, va_list ap);
void					ifhex(const char *str, t_struct *f, va_list ap);
void					ifhex_cap(const char *str, t_struct *f, va_list ap);
void					ifpercentage(const char *str, t_struct *f, va_list ap);
void					print_cero(int j, t_struct *f);
void					print_str(char *s, t_struct *f);
int						print_i(t_struct *f, va_list ap);
void					print_ii(int ancho, t_struct *f);
void					print_int_i(int ancho, t_struct *f);
void					print_int_prec_minus_i(int var, int ancho, t_struct *f);
void					print_int_prec_i(int ancho, t_struct *f);
int						print_unsing_zero_i(int ancho, t_struct *f, va_list ap);
void					print_unsing_zero_ii(int ancho, t_struct *f);

#endif
