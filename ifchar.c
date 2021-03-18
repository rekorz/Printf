/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:25:44 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:25:48 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_struct *f, va_list ap)
{
	int		ancho;
	char	c;

	ancho = 0;
	if (f->ast != 0)
		ancho = va_arg(ap, int);
	c = va_arg(ap, int);
	if (f->width != 0)
		ancho = f->width;
	if (ancho != 0)
		ancho = ancho - 1;
	if (f->minus == 1)
	{
		write(1, &c, 1);
		f->nprinted++;
	}
	if (ancho > 0)
		print_space(ancho, f);
	if (f->minus == 0)
	{
		write(1, &c, 1);
		f->nprinted++;
	}
}

void	ifchar(const char *str, t_struct *f, va_list ap)
{
	f->saida = 1;
	while (str[f->i] != 'c')
	{
		if (str[f->i] == '-')
			f->minus = 1;
		else if (str[f->i] >= '0' && str[f->i] <= '9')
			f->width = f->width * 10 + (str[f->i] - '0');
		else if (str[f->i] == '*')
			f->ast = 1;
		f->i++;
	}
	print_char(f, ap);
}
