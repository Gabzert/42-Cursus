/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:53 by gfantech          #+#    #+#             */
/*   Updated: 2023/06/22 17:28:36 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int searched)
{
	typename T::iterator it = std::find(container.begin(), container.end(), searched);
	return (it);
}
