/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifint_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:12 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:15 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_i(t_struct *f, va_list ap)
{
	int ancho;

	ancho = f->width;
	f->integer = va_arg(ap, int);
	f->len = ft_strlen(ft_itoa(f->integer));
	if (f->width != 0)
		ancho = f->width;
	if (ancho < 0)
		ancho = ancho * (-1);
	return (ancho);
}

void	print_ii(int ancho, t_struct *f)
{
	if (ancho > f->precisionft && f->minus == 0)
		print_space(ancho - f->precisionft, f);
	if (f->precisionft > 0)
		print_cero(f->precisionft, f);
	if (ancho > f->precisionft && f->minus == 1)
		print_space(ancho - f->precisionft, f);
}

void	print_int_i(int ancho, t_struct *f)
{
	if (f->zero != 0 && ancho > f->len && f->minus == 0)
		print_cero(ancho - f->len, f);
	print_str(ft_itoa(f->integer), f);
	if (ancho > f->len && f->minus == 1)
		print_space(ancho - f->len, f);
}

void	print_int_prec_minus_i(int var, int ancho, t_struct *f)
{
	if (f->precisionft > f->len)
		print_cero(f->precisionft - f->len, f);
	if (f->integer != 0)
		print_str(ft_itoa(f->integer), f);
	if (f->precisionft > f->len && ancho > f->precisionft && var == 0)
		print_space(ancho - f->precisionft, f);
	if (f->precisionft > f->len && ancho > f->precisionft && var == 1)
		print_space(ancho - f->precisionft - 1, f);
	if (f->precisionft < f->len && ancho > f->precisionft && var == 0)
		print_space(ancho - f->len, f);
	if (f->precisionft < f->len && ancho > f->precisionft && var == 1)
		print_space(ancho - f->len - 1, f);
}

void	print_int_prec_i(int ancho, t_struct *f)
{
	int tern;

	f->len = ft_strlen(ft_itoa(f->integer));
	if (f->integer < 0)
		ancho = ancho - 1;
	if (f->integer < 0)
		f->len = f->len - 1;
	if (f->astft < 0)
		f->precisionft *= -1;
	tern = (f->len > f->precisionft ? f->len : f->precisionft);
	if (ancho > tern && ancho > 0)
		print_space(ancho - tern, f);
}
