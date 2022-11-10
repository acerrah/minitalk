/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:20:27 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:20:36 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_dec2(t_printfb *print)
{
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	else
		print->int_tmp = 0;
	if (print->fdot > print->dlen)
		ft_print_dec2_1(print);
	else
		ft_print_dec2_2(print);
}

void	ft_print_dec2_1(t_printfb *print)
{
	int	i;

	i = 0;
	while (print->int_tmp > print->fdot
		+ (int)(print->fplus) + (int)(print->neg))
	{
		ft_putchar_fd1(' ', 1, print);
		print->int_tmp--;
	}
	if (print->neg)
		ft_putchar_fd1('-', 1, print);
	ft_print2(print);
	while (i < (print->fdot) - (int)(print->fplus) - print->dlen)
	{
		ft_putchar_fd1('0', 1, print);
		i++;
	}
	if (print->dvalue != 0 || print->fdot != 0 || !print->fdotdot)
	{
		ft_putnbr_fd(print->dvalue, 1);
		print->rtn += print->dlen;
	}
}

void	ft_print_dec2_2(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->neg && !print->fdot && !print->fnum)
		ft_putchar_fd1('-', 1, print);
	while (i++ < (print->int_tmp) - (print->dlen)
		- (int)(print->fplus) - (int)(print->neg))
	{
		if (print->fzero && !print->fdotdot)
			ft_putchar_fd1('0', 1, print);
		else
			ft_putchar_fd1(' ', 1, print);
	}
	if (print->neg && (print->fdot || print->fnum))
		ft_putchar_fd1('-', 1, print);
	ft_print2(print);
	if (print->dvalue != 0 || print->fdot != 0 || !print->fdotdot)
	{
		ft_putnbr_fd(print->dvalue, 1);
		print->rtn += print->dlen;
	}
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
}
