/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_star2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:11 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:12 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print3(va_list arg, t_printfb *print)
{
	if (print->format == 'p')
	{
		print->fconvert = TRUE;
		print->fconlen = 2;
		print->format += 8;
		print->unsvalue = va_arg(arg, unsigned long);
		print->hexlen = ft_hexa_x_len(print->unsvalue);
		if (print->fnegative)
			ft_print_hexa(print);
		else
			ft_print_hexa2(print);
	}
	else if (print->format == 'u')
	{
		print->fplus = FALSE;
		print->fspace = FALSE;
		print->unsvalue = va_arg(arg, unsigned int);
		print->ulen = ft_unsigned_len(print->unsvalue);
		if (print->fnegative)
			ft_print_unsigned(print);
		else
			ft_print_unsigned2(print);
	}
	else
		ft_print4(arg, print);
}

void	ft_print4(va_list arg, t_printfb *print)
{	
	if (print->format == 's')
	{
		print->string = va_arg(arg, char *);
		if (print->string == NULL)
			print->string = "(null)";
		print->slen = ft_strlen(print->string);
		if (print->fdotdot && print->fdot < print->slen)
			print->slen = print->fdot;
		if (print->fnegative)
			ft_print_string(print);
		else
			ft_print_string2(print);
	}
	else if (print->format == 'c')
	{
		print->dvalue = va_arg(arg, int);
		if (print->fnegative)
			ft_print_char(print);
		else
			ft_print_char2(print);
	}
}
