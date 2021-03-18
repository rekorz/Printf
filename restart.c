/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:18 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:27:33 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart(t_struct *f)
{
	f->len = 0;
	f->integer = 0;
	f->width = 0;
	f->minus = 0;
	f->zero = 0;
	f->precision = 0;
	f->precisionft = 0;
	f->ast = 0;
	f->saida = 0;
	f->ifpoint = 0;
	f->astft = 0;
}
