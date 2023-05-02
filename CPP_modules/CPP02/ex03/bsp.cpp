/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:56:02 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/02 12:47:10 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <math.h>

/*
determinante matrice :
| a.x b.x c.x |
| a.y b.y c.y |
|  1   1   1  |
*/
Fixed &determinant(Point a, Point b, Point c)
{
    return (a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY()) - (c.getX() * b.getY() + b.getX() * a.getY() + a.getX() * c.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed det_abp = determinant(a, b, point);
    Fixed det_bcp = determinant(b, c, point);
    Fixed det_cap = determinant(c, a, point);

    Fixed det_abc = determinant(a, b, c);

	//se i determinanti dei tre triangoli formati dal punto e due vertici hanno 
	//lo stesso segno di quello del triandolo allora il punto e' dentro
    if (det_abc >= 0)
        return (det_abp >= 0 && det_bcp >= 0 && det_cap >= 0);
	else
        return (det_abp <= 0 && det_bcp <= 0 && det_cap <= 0);
}
