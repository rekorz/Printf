/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:40 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:43 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_struct *f, va_list ap)
{
	int		ancho;
	char	*string;

	ancho = f->width;
	string = va_arg(ap, char*);
	if (string == NULL)
		string = "(null)";
	f->len = ft_strlen(string);
	if (f->width != 0)
		ancho = f->width;
	if (ancho < 0)
	{
		ancho = ancho * (-1);
		f->minus = 1;
	}
	if (ancho > f->len && f->minus == 0 && f->zero == 0)
		print_space(ancho - f->len, f);
	if (ancho > f->len && f->minus == 0 && f->zero == 1)
		print_cero(ancho - f->len, f);
	print_str(string, f);
	if (ancho > f->len && f->minus == 1)
		print_space(ancho - f->len, f);
}

void	print_str_prec(t_struct *f, va_list ap)
{
	int		ancho;
	char	*string;

	ancho = f->width;
	string = va_arg(ap, char*);
	if (string == NULL)
		string = "(null)";
	f->len = ft_strlen(string);
	if (f->precisionft < 0)
		f->precisionft = f->len;
	if (f->width != 0)
		ancho = f->width;
	if (ancho < 0)
		ancho = ancho * (-1);
	f->len = (f->len < f->precisionft ? f->len : f->precisionft);
	if (ancho > f->len && f->minus == 0)
		print_space(ancho - f->len, f);
	print_str(string, f);
	if (ancho > f->len && f->minus == 1)
		print_space(ancho - f->len, f);
}

void	ifstring(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != 's')
		ft_flags(str, f, ap);
	if (f->precision == 1)
		print_str_prec(f, ap);
	if (f->precision == 0)
		print_string(f, ap);
}
