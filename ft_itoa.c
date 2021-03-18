/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egallego <egallego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:24:28 by egallego          #+#    #+#             */
/*   Updated: 2021/03/18 17:43:53 by egallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_string(int n, char *s, int i)
{
	s += i + 2;
	*--s = '\0';
	if (n < 0)
	{
		while (n != 0)
		{
			*--s = '0' + ((-n) % 10);
			n /= 10;
		}
		*--s = '-';
		return (s);
	}
	if (n >= 0)
	{
		*--s = '\0';
		while (n != 0)
		{
			*--s = '0' + (n % 10);
			n /= 10;
		}
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		n1;

	i = 0;
	n1 = (long int)n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (n1 != 0)
	{
		n1 /= 10;
		i++;
	}
	s = malloc(i + 2);
	if (s == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	itoa_string(n, s, i);
	return (s);
}
