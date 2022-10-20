/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:01:08 by gfantech          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:10 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	format_initializer(t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->parse = ' ';
}
