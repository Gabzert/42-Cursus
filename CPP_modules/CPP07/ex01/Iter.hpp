/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:34:57 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 12:04:55 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T *array, int size, void (&function)(T&))
{
    for (int i = 0; i < size; i++)
    {
        function(array[i]);
    }
}
