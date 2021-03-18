/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:23:34 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:23:43 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convers_loop(const char *str, t_struct *f, va_list ap)
{
	int m;

	m = f->i;
	while (str[m] && f->saida == 0)
	{
		if (str[m] == 'd' || str[m] == 'i')
			ifinteger(str, f, ap);
		else if (str[m] == 'c')
			ifchar(str, f, ap);
		else if (str[m] == 's')
			ifstring(str, f, ap);
		else if (str[m] == 'p')
			ifpointer(str, f, ap);
		else if (str[m] == 'x')
			ifhex(str, f, ap);
		else if (str[m] == 'X')
			ifhex_cap(str, f, ap);
		else if (str[m] == 'u')
			ifunsigned(str, f, ap);
		else if (str[m] == '%')
			ifpercentage(str, f, ap);
		m++;
	}
}

void	convers(const char *str, t_struct *f, va_list ap)
{
	f->i++;
	convers_loop(str, f, ap);
	f->i++;
}
