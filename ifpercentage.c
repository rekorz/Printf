/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercentage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:26 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:28 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per_prec(t_struct *f)
{
	if (f->precisionft > 0)
		print_zero(f->precisionft, f);
}

int		per_prec(int j, t_struct *f)
{
	int k;

	f->zero = 0;
	f->precisionft = f->precisionft - f->len;
	k = j - f->precisionft;
	return (k);
}

void	print_per(t_struct *f)
{
	int		j;
	char	c;

	j = f->width;
	c = '%';
	if (f->width != 0)
		j = f->width;
	if (j != 0)
		j = j - 1;
	if (f->precision == 1)
		j = per_prec(j, f);
	if (f->zero != 0 && j > 0)
		print_zero(j, f);
	if (f->zero == 0 && j > 0)
		print_space(j, f);
	if (f->precision == 1)
		print_per_prec(f);
	write(1, &c, 1);
	f->nprinted++;
}

void	print_per_minus(t_struct *f)
{
	int		j;
	char	c;

	j = f->width;
	c = '%';
	f->len = 1;
	if (f->width != 0)
		j = f->width;
	if (j != 0)
		j = j - f->len;
	if (f->precision == 1)
		j = per_prec(j, f);
	if (f->precision == 1)
		print_per_prec(f);
	write(1, &c, 1);
	if (j > 0)
		print_space(j, f);
	f->nprinted++;
}

void	ifpercentage(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != '%')
		ft_flags(str, f, ap);
	if (f->minus == 1)
		print_per_minus(f);
	else
		print_per(f);
}
