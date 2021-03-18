/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifinteger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:19 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:22 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_struct *f, va_list ap)
{
	int	ancho;

	ancho = print_i(f, ap);
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
	print_ii(ancho, f);
}

void	print_int(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = f->width;
	f->integer = va_arg(ap, int);
	if (f->integer == 0)
		return ;
	f->len = ft_strlen(ft_itoa(f->integer));
	if (f->width != 0)
		ancho = f->width;
	if (ancho < 0)
	{
		f->minus = 1;
		ancho = ancho * (-1);
	}
	if (ancho > f->len && f->minus == 0 && f->zero == 0)
		print_space(ancho - f->len, f);
	if (f->integer < 0 && f->integer != -2147483648)
	{
		ancho = ancho - 1;
		f->len = f->len - 1;
		write(1, "-", 1);
		f->nprinted++;
		f->integer = f->integer * (-1);
	}
	print_int_i(ancho, f);
}

void	print_int_prec_minus(t_struct *f, va_list ap)
{
	int		ancho;
	int		var;

	var = 0;
	ancho = f->width;
	f->integer = va_arg(ap, int);
	if (f->integer == 0)
		return ;
	f->len = ft_strlen(ft_itoa(f->integer));
	if (f->width != 0)
		ancho = f->width;
	if (ancho < 0)
		ancho = ancho * (-1);
	if (f->integer < 0 && f->integer != -2147483648)
	{
		var = 1;
		f->len = f->len - 1;
		write(1, "-", 1);
		f->nprinted++;
		f->integer = f->integer * (-1);
	}
	print_int_prec_minus_i(var, ancho, f);
}

void	print_int_prec(t_struct *f, va_list ap)
{
	int		ancho;

	if (f->width < 0)
	{
		f->minus = 1;
		f->width *= -1;
		return ;
	}
	ancho = f->width;
	f->integer = va_arg(ap, int);
	if (f->integer == 0)
		return ;
	print_int_prec_i(ancho, f);
	if (f->integer < 0 && f->integer != -2147483648)
	{
		write(1, "-", 1);
		f->nprinted++;
		f->integer = f->integer * (-1);
	}
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	print_str(ft_itoa(f->integer), f);
}

void	ifinteger(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != 'd' && str[f->i] != 'i')
		ft_flags(str, f, ap);
	if (f->precision == 1 && f->minus == 0)
		print_int_prec(f, ap);
	if (f->precision == 1 && f->minus == 1)
		print_int_prec_minus(f, ap);
	if (f->precision == 0)
		print_int(f, ap);
	if (f->integer == 0)
		print(f, ap);
}
