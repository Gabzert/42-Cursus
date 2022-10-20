/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:52:34 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/17 15:52:37 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_formatter(t_format *f)
{
	if (f->plus == 1 && f->space == 1)
		f->space = 0;
	if (f->minus == 1 && f->zero == 1)
		f->zero = 0;
	if ((f->spec == 'd' || f->spec == 'i' || f->spec == 'u' || f->spec == 'X'
			|| f->spec == 'x') && f->zero == 1)
		f->parse = '0';
}