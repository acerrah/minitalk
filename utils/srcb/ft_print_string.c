/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:24 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:26 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_string(t_printfb *print)
{
	int	i;

	i = 0;
	print->int_tmp = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	if (print->int_tmp < print->fdot)
	print->fdot = print->int_tmp;
	if (print->slen > print->fdot && print->fdotdot)
	print->slen = print->fdot;
	ft_print_string1_1(print, &i);
}

void	ft_print_string1_1(t_printfb *print, int *i)
{
	while ((*i) < print->slen && print->string[*i])
	{
		ft_putchar_fd(print->string[*i], 1);
		(*i)++;
		print->rtn++;
	}
	while ((*i) < print->fdot)
	{
		ft_putchar_fd(' ', 1);
		(*i)++;
		print->rtn++;
	}
	while ((*i)++ < print->int_tmp)
	{
		ft_putchar_fd(' ', 1);
		print->rtn++;
	}
}

void	ft_print_string2(t_printfb *print)
{
	int	i;

	i = 0;
	if (print->fzero)
		print->int_tmp = print->fzero;
	else if (print->fnum)
		print->int_tmp = print->fnum;
	while (i < (print->int_tmp) - print->slen)
	{
		if (print->fzero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		i++;
	}
	print->rtn += i;
	i = 0;
	while (i < print->slen)
	{
		ft_putchar_fd(print->string[i], 1);
		i++;
		print->rtn++;
	}
}
