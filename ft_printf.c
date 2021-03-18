/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:24:36 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:24:40 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_zero(int j, t_struct *f)
{
	while (j > 0)
	{
		write(1, "0", 1);
		f->nprinted++;
		j--;
	}
	return (j);
}

void			print_space(int j, t_struct *f)
{
	while (j > 0)
	{
		write(1, " ", 1);
		f->nprinted++;
		j--;
	}
}

void			putcha(const char *str, t_struct *f)
{
	write(1, &str[f->i], 1);
	f->nprinted++;
	f->i++;
}

void			putstr(char *s, t_struct *f)
{
	int			k;

	k = 0;
	while (f->len != 0)
	{
		write(1, &s[k++], 1);
		f->len--;
		f->nprinted++;
	}
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	*f;

	if (!(f = malloc(sizeof(t_struct))))
		return (0);
	f->i = 0;
	f->nprinted = 0;
	va_start(ap, str);
	while (str[f->i])
	{
		restart(f);
		if (str[f->i] == '%')
			convers(str, f, ap);
		else
			putcha(str, f);
	}
	va_end(ap);
	free(f);
	return (f->nprinted);
}
