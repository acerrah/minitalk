/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:17 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:19 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print2( t_printfb *print)
{
	if (print->fconvert == TRUE)
	{
		if (print->format == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		print->rtn += 2;
	}
	else if ((print->fplus == TRUE || print->fspace == TRUE)
		&& (print->format == 'd' || print->format == 'i'))
	{
		if (print->dvalue >= 0)
		{
			if (print->fplus == TRUE)
				ft_putstr_fd("+", 1);
			else
				ft_putstr_fd(" ", 1);
			print->rtn++;
		}
	}
}

void	ft_print(va_list arg, t_printfb *print)
{
	if (print->format == 'd' || print->format == 'i')
	{
		print->dvalue = va_arg(arg, int);
		if (print->dvalue < 0)
		{	
			print->dvalue *= -1;
			print->neg = TRUE;
			print->fplus = FALSE;
			print->fspace = FALSE;
		}
		print->dlen = ft_decimal_len(print->dvalue);
		if (print->fnegative)
			ft_print_dec(print);
		else
			ft_print_dec2(print);
	}
	else
		ft_print2_2(arg, print);
}

void	ft_print2_2(va_list arg, t_printfb *print)
{
	if (print->format == 'x' || print->format == 'X')
	{
		print->unsvalue = va_arg(arg, unsigned int);
		if (print->unsvalue == 0)
			print->fconvert = FALSE;
		if (print->fconvert == TRUE)
			print->fconlen = 2;
		else
			print->fconlen = 0;
		print->hexlen = ft_hexa_x_len(print->unsvalue);
		if (print->fdot == 0 && print->unsvalue == 0)
			print->fdot = 0;
		else if (print->fdot < print->hexlen)
			print->fdot = print->hexlen;
		if (print->fnegative)
			ft_print_hexa(print);
		else
			ft_print_hexa2(print);
	}
	else if (print->format == '%')
		ft_putchar_fd1('%', 1, print);
	else
		ft_print3(arg, print);
}
