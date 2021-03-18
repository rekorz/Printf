/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:25:37 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:25:40 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa(unsigned int nbr)
{
	long	n;
	size_t	len;
	char	*str;
	long	aux;

	n = nbr;
	len = (n > 0) ? 0 : 1;
	n = (n > 0) ? n : -n;
	while (nbr)
		nbr = len++ ? nbr / 16 : nbr / 16;
	str = (char *)malloc(sizeof(str) * len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	while (n > 0)
	{
		aux = n % 16;
		if (aux < 10)
			*(str + len--) = n % 16 + '0';
		else
			*(str + len--) = n % 16 + 87;
		n /= 16;
	}
	return (ft_uitoa_ret(len, str));
}

char		*ft_utoa_cap(unsigned int nbr)
{
	long	n;
	size_t	len;
	char	*str;
	long	aux;

	n = nbr;
	len = (n > 0) ? 0 : 1;
	n = (n > 0) ? n : -n;
	while (nbr)
		nbr = len++ ? nbr / 16 : nbr / 16;
	str = (char *)malloc(sizeof(str) * len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	while (n > 0)
	{
		aux = n % 16;
		if (aux < 10)
			*(str + len--) = n % 16 + '0';
		else
			*(str + len--) = n % 16 + 55;
		n /= 16;
	}
	return (ft_uitoa_ret(len, str));
}
