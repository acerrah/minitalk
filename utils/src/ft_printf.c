/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:32 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:22:33 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		pars;
	t_printf	specter;

	va_start(pars, str);
	specter.rtn = 0;
	check_arg(str, pars, &specter);
	va_end(pars);
	return (specter.rtn);
}
