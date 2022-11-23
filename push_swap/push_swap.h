/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:58:55 by gfantech          #+#    #+#             */
/*   Updated: 2022/11/15 11:58:59 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	merge(char **a, int first, int center, int last);
void	sort(char **a, int first, int last);
void	push(char **x, char **y);
void	shift(char **a, int rot);
void	swap(char **a);

#endif
