/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:27 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:22:29 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_to_hexa(t_printf *prnt, unsigned int nb)
{
	char			*base1;
	char			*base2;

	base2 = "0123456789ABCDEF";
	base1 = "0123456789abcdef";
	if (prnt->flagstart == 'x')
	{
		if (nb >= 16)
		{
			decimal_to_hexa(prnt, nb / 16);
		}
		ft_putchar_fd(base1[nb % 16], 1);
		prnt->rtn++;
	}
	if (prnt->flagstart == 'X')
	{
		if (nb >= 16)
		{
			decimal_to_hexa(prnt, nb / 16);
		}
		ft_putchar_fd(base2[nb % 16], 1);
		prnt->rtn++;
	}
}

void	decimal_to_hexap(t_printf *prnt, unsigned long nb)
{
	char	*base1;

	base1 = "0123456789abcdef";
	if (prnt->flagstart == 'p')
	{
		if (nb >= 16)
		{
			decimal_to_hexap(prnt, nb / 16);
		}
		ft_putchar_fd(base1[nb % 16], 1);
		prnt->rtn++;
	}
}

void	unsigned_convert(t_printf *prnt, unsigned int nb)
{
	char	*base;

	base = "0123456789";
	if (prnt->flagstart == 'u')
	{
		if (nb >= 10)
		{
			unsigned_convert(prnt, nb / 10);
		}
		ft_putchar_fd(base[nb % 10], 1);
		prnt->rtn++;
	}
}
