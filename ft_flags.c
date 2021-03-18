/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:24:05 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:43:53 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_prec(const char *str, t_struct *f, va_list ap)
{
	f->precision = 1;
	if (str[f->i + 1] >= '0' && str[f->i + 1] <= '9')
		while (str[f->i + 1] >= '0' && str[f->i + 1] <= '9')
			f->precisionft = f->precisionft * 10 + (str[++f->i] - '0');
	else if (str[f->i + 1] == '*')
	{
		f->precisionft = va_arg(ap, int);
		f->i++;
	}
}

void	ft_flags(const char *str, t_struct *f, va_list ap)
{
	if (str[f->i] == '-')
		f->minus = 1;
	else if (str[f->i] == '0' && f->width == 0)
		f->zero = 1;
	else if (str[f->i] >= '0' && str[f->i] <= '9')
		f->width = f->width * 10 + (str[f->i] - '0');
	else if (str[f->i] == '.')
		ft_flags_prec(str, f, ap);
	else if (str[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		f->ast = 1;
	}
	f->i++;
}

void	print_str(char *s, t_struct *f)
{
	int k;
	int l;

	k = 0;
	l = f->len;
	while (l != 0)
	{
		write(1, &s[k++], 1);
		l--;
		f->nprinted++;
	}
}

void	print_cero(int j, t_struct *f)
{
	while (j > 0)
	{
		write(1, "0", 1);
		f->nprinted++;
		j--;
	}
}
