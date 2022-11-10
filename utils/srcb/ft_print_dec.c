/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:20:55 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:20:59 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_dec(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	else
		print->int_tmp = 0;
	ft_print2(print);
	if (print->neg == TRUE)
		ft_putchar_fd1('-', 1, print);
	while (i < (print->fdot) - print->dlen)
	{
		ft_putchar_fd1('0', 1, print);
		i++;
	}
	ft_print_dec1_1(print, &i);
}

void	ft_print_dec1_1(t_printfb *print, int *i)
{
	if (print->dvalue != 0 || print->fdot != 0 || !print->fdotdot)
	{
		ft_putnbr_fd(print->dvalue, 1);
		print->rtn += print->dlen;
	}
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
	while ((*i) + print->dlen < print->int_tmp
		- (int)(print->fplus) - (int)(print->neg))
	{
		ft_putchar_fd1(' ', 1, print);
		(*i)++;
	}
}
