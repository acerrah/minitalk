/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:04 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:06 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_hexa(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	ft_print2(print);
	while (i < (print->fdot) - print->hexlen)
	{
		ft_putchar_fd1('0', 1, print);
		i++;
	}
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		decimal_to_hexa(print, print->unsvalue, print->fdot);
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
	while (i + (print->hexlen) < (print->int_tmp) - print -> fconlen)
	{
		ft_putchar_fd1(' ', 1, print);
		i++;
	}
}

void	ft_print_hexa2(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	else
		print->int_tmp = 0;
	if (print->fdot > print->hexlen)
		ft_print_hexa2_1(print, &i);
	else
		ft_print_hexa2_2(print, &i);
}

void	ft_print_hexa2_1(t_printfb *print, int *i)
{
	while (print->int_tmp > (print->fdot) + print -> fconlen)
	{
		ft_putchar_fd1(' ', 1, print);
		print->int_tmp--;
	}
	ft_print2(print);
	while ((*i) < (print->fdot) - (print->hexlen) - print -> fconlen)
	{
		ft_putchar_fd1('0', 1, print);
		(*i)++;
	}
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		decimal_to_hexa(print, print->unsvalue, print->fdot);
}

void	ft_print_hexa2_2(t_printfb *print, int *i)
{
	while ((*i)++ < (print->int_tmp)
		- (print->hexlen) - print -> fconlen)
	{
		if (print->fzero && !print->fdotdot)
			ft_putchar_fd1('0', 1, print);
		else
			ft_putchar_fd1(' ', 1, print);
	}
	ft_print2(print);
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		decimal_to_hexa(print, print->unsvalue, print->fdot);
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
}
