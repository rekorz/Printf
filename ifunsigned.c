/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:54 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:56 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsig_zero(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = 0;
	ancho = print_unsing_zero_i(ancho, f, ap);
	if (ancho == 0 && f->precision == 0)
	{
		print_cero(1, f);
		if (ancho > f->len && f->zero == 1)
			print_cero(ancho - f->len, f);
		return ;
	}
	if (ancho != 0 && f->precision == 0)
	{
		if (f->zero != 0)
			print_cero(ancho, f);
		if (f->zero != 0)
			return ;
		if (f->minus != 0)
			print_cero(1, f);
		print_space(ancho - 1, f);
		if (f->minus == 0)
			print_cero(1, f);
		return ;
	}
	print_unsing_zero_ii(ancho, f);
}

void	print_unsig(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = f->width;
	f->unsig = va_arg(ap, int);
	if (f->unsig == 0)
		return ;
	f->len = ft_strlen(ft_utoa_uns(f->unsig));
	if (ancho > f->len && f->minus == 0 && f->zero == 0)
		print_space(ancho - f->len, f);
	if (f->zero != 0 && ancho > f->len && f->minus == 0)
		print_cero(ancho - f->len, f);
	print_str(ft_utoa_uns(f->unsig), f);
	if (ancho > f->len && f->minus == 1)
		print_space(ancho - f->len, f);
}

void	print_unsig_prec_minus(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = f->width;
	f->unsig = va_arg(ap, int);
	if (f->unsig == 0)
		return ;
	f->len = ft_strlen(ft_utoa_uns(f->unsig));
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	if (f->unsig != 0)
		print_str(ft_utoa_uns(f->unsig), f);
	if (f->precisionft > f->len && ancho > f->precisionft)
		print_space(ancho - f->precisionft, f);
	if (f->precisionft < f->len && ancho > f->precisionft)
		print_space(ancho - f->len, f);
}

void	print_unsig_prec(t_struct *f, va_list ap)
{
	int		ancho;
	int		tern;

	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
		return ;
	}
	ancho = f->width;
	f->unsig = va_arg(ap, int);
	if (f->unsig == 0)
		return ;
	f->len = ft_strlen(ft_utoa_uns(f->unsig));
	if (f->unsig < 0)
		ancho = ancho - 1;
	if (f->unsig < 0)
		f->len = f->len - 1;
	tern = (f->len > f->precisionft ? f->len : f->precisionft);
	if (ancho > tern && ancho > 0)
		print_space(ancho - tern, f);
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	print_str(ft_utoa_uns(f->unsig), f);
}

void	ifunsigned(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != 'u')
		ft_flags(str, f, ap);
	if (f->precision == 1 && f->minus == 0)
		print_unsig_prec(f, ap);
	if (f->precision == 1 && f->minus == 1)
		print_unsig_prec_minus(f, ap);
	if (f->precision == 0)
		print_unsig(f, ap);
	if (f->unsig == 0)
		print_unsig_zero(f, ap);
}
