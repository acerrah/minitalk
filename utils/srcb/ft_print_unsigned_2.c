/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:33 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:34 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_unsigned2(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	if (print->fdot > print->ulen)
		ft_print_unsigned3(print, &i);
	else
		ft_print_unsigned4(print, &i);
}

void	ft_print_unsigned3(t_printfb *print, int *i)
{
	while (print->int_tmp > print->fdot)
	{
		ft_putchar_fd1(' ', 1, print);
		print->int_tmp--;
	}
	while ((*i) < print->fdot - print->ulen)
	{
		ft_putchar_fd1('0', 1, print);
		(*i)++;
	}
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		ft_putunsigned(print->unsvalue, 1, print);
}

void	ft_print_unsigned4(t_printfb *print, int *i)
{
	while ((*i)++ < print->int_tmp - print->ulen)
	{
		if (print->fzero && !print->fdotdot)
			ft_putchar_fd1('0', 1, print);
		else
			ft_putchar_fd1(' ', 1, print);
	}
	if (print->unsvalue != 0 || print->fdot != 0 || !print->fdotdot)
		ft_putunsigned(print->unsvalue, 1, print);
	else if (!(print->fdot == 0 && print->dvalue == 0
			&& print->fnum == 0 && print->fzero == 0))
		ft_putchar_fd1(' ', 1, print);
}
