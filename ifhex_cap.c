/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex_cap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:25:53 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:25:56 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_cap(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = 0;
	if (f->ast != 0)
		ancho = va_arg(ap, int);
	f->unsig = va_arg(ap, unsigned int);
	f->len = ft_strlen((ft_utoa_cap(f->unsig)));
	if (f->width != 0)
		ancho = f->width;
	if (ancho > f->len && f->minus == 0 && f->zero == 0)
		print_space(ancho - f->len, f);
	if (f->zero != 0 && ancho > f->len && f->minus == 0)
		print_cero(ancho - f->len, f);
	print_str(ft_utoa_cap(f->unsig), f);
	if (ancho > f->len && f->minus == 1)
		print_space(ancho - f->len, f);
}

void	print_hex_prec_minus_cap(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = 0;
	if (f->ast != 0)
		ancho = va_arg(ap, int);
	f->unsig = va_arg(ap, unsigned int);
	f->len = ft_strlen((ft_utoa_cap(f->unsig)));
	if (f->width != 0)
		ancho = f->width;
	if (f->unsig == 0)
		f->len = 0;
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	if (f->unsig != 0)
		print_str(ft_utoa_cap(f->unsig), f);
	if (f->precisionft >= f->len && ancho > f->precisionft)
		print_space(ancho - f->precisionft, f);
	if (f->precisionft < f->len && ancho > f->precisionft)
		print_space(ancho - f->len, f);
}

void	print_hex_prec_cap(t_struct *f, va_list ap)
{
	int		ancho;
	int		tern;

	ancho = f->width;
	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
		return ;
	}
	if (f->precisionft < 0)
		f->precisionft = 0;
	f->unsig = va_arg(ap, unsigned int);
	f->len = ft_strlen((ft_utoa_cap(f->unsig)));
	if (f->unsig == 0)
		f->len = 0;
	tern = (f->len > f->precisionft ? f->len : f->precisionft);
	if (ancho > tern && ancho > 0)
		print_space(ancho - tern, f);
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	if (f->unsig != 0)
		print_str(ft_utoa_cap(f->unsig), f);
}

void	ifhex_cap(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != 'X')
		ft_flags(str, f, ap);
	if (f->precision == 1 && f->minus == 0)
		print_hex_prec_cap(f, ap);
	if (f->precision == 1 && f->minus == 1)
		print_hex_prec_minus_cap(f, ap);
	if (f->precision == 0)
		print_hex_cap(f, ap);
}
