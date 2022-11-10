/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:38 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:40 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putunsigned(unsigned int n, int fd, t_printfb *print)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, fd, print);
		ft_putunsigned(n % 10, fd, print);
	}
	else
		ft_putchar_fd1(n + '0', fd, print);
}

void	ft_print_unsigned(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	ft_print2(print);
	while (i < (print->fdot) - print->ulen)
	{
		ft_putchar_fd1('0', 1, print);
		i++;
	}
	ft_print_unsigned1_1(print, &i);
}

void	ft_print_unsigned1_1(t_printfb *print, int *i)
{
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		ft_putunsigned(print->unsvalue, 1, print);
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
	while ((*i) + print->ulen < print->int_tmp)
	{
		ft_putchar_fd1(' ', 1, print);
		(*i)++;
	}
}
