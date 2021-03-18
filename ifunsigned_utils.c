/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifunsigned_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:26:48 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:26:50 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unsing_zero_i(int ancho, t_struct *f, va_list ap)
{
	ancho = f->width;
	f->unsig = va_arg(ap, int);
	f->len = ft_strlen(ft_utoa_uns(f->unsig));
	return (ancho);
}

void	print_unsing_zero_ii(int ancho, t_struct *f)
{
	if (ancho > f->precisionft && f->minus == 0)
		print_space(ancho - f->precisionft, f);
	if (f->precisionft > 0)
		print_cero(f->precisionft, f);
	if (ancho > f->precisionft && f->minus == 1)
		print_space(ancho - f->precisionft, f);
}
