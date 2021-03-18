/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:23:49 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:43:53 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int cont;
	int n;

	n = 0;
	cont = 0;
	while (((*str == ' ') || (*str == '\n') || (*str == '\t') ||
				(*str == '\v') || (*str == '\f') || (*str == '\r') ||
				(*str == '-') || (*str == '+')) && (cont == 0))
	{
		if (*str == '+')
			cont = 1;
		if (*str == '-')
			cont = 2;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
		if ((*str < '0' || *str > '9') && cont <= 1)
			return (n);
		if ((*str < '0' || *str > '9') && cont == 2)
			return (n * (-1));
	}
	return (0);
}
