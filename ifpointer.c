/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:33 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:36 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = 0;
	if (f->ast != 0)
		ancho = va_arg(ap, int);
	f->uli = va_arg(ap, unsigned long int);
	f->len = ft_strlen(ft_uitoa(f->uli));
	if (f->width != 0)
		ancho = f->width;
	if (f->minus == 0 && ancho > (f->len + 2) && ancho > 0)
		print_space(ancho - (f->len + 2), f);
	write(1, "0", 1);
	write(1, "x", 1);
	f->nprinted = f->nprinted + 2;
	print_str(ft_uitoa(f->uli), f);
	if (f->minus == 1 && ancho > f->len && ancho > 0)
		print_space(ancho - (f->len + 2), f);
}

void	print_pointer_prec(t_struct *f, va_list ap)
{
	int		ancho;

	ancho = 0;
	if (f->ast != 0)
		ancho = va_arg(ap, int);
	f->uli = va_arg(ap, unsigned long int);
	f->len = ft_strlen(ft_uitoa(f->uli));
	if (f->width != 0)
		ancho = f->width;
	f->len = (f->len > f->precisionft ? f->len : f->precisionft);
	if (f->uli == 0)
		f->len = f->len - 1;
	if (f->minus == 0 && ancho > (f->len + 2) && ancho > 0)
		print_space((ancho - (f->len + 2)), f);
	write(1, "0", 1);
	write(1, "x", 1);
	f->nprinted = f->nprinted + 2;
	if (f->precisionft > (f->len + 2))
		print_cero(f->precisionft - (f->len + 2), f);
	if (f->precisionft != 0)
		print_str(ft_uitoa(f->uli), f);
	if (f->minus == 1 && ancho > (f->len + 2) && ancho > 0)
		print_space(ancho - (f->len + 2), f);
}

void	ifpointer(const char *str, t_struct *f, va_list ap)
{
	f->ifpoint = 1;
	f->saida = 1;
	while (str[f->i] != 'p')
	{
		if (str[f->i] == '-')
			f->minus = 1;
		else if (str[f->i] == '0' && f->width == 0)
			f->zero = 1;
		else if (str[f->i] >= '0' && str[f->i] <= '9')
			f->width = f->width * 10 + (str[f->i] - '0');
		else if (str[f->i] == '.')
		{
			f->precision = 1;
			if (str[f->i + 1] >= '0' && str[f->i + 1] <= '9')
				while (str[f->i + 1] >= '0' && str[f->i + 1] <= '9')
					f->precisionft = f->precisionft * 10 + (str[++f->i] - '0');
		}
		else if (str[f->i] == '*')
			f->ast = 1;
		f->i++;
	}
	if (f->precision == 1)
		print_pointer_prec(f, ap);
	if (f->precision == 0)
		print_pointer(f, ap);
}
