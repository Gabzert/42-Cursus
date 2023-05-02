/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:06:34 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/02 12:45:03 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0) , y(0)
{}

Point::Point(const Fixed &n1, const Fixed &n2) : x(n1) , y(n2)
{}

Point::Point(const Point &a) : x(a.x) , y(a.y)
{}

Point::~Point()
{}

Fixed Point::getX() const
{
    return(this->x);
}

Fixed Point::getY() const
{
    return(this->y);
}

Point& Point::operator=(const Point& a)
{
    if (this != &a)
    {
        
    }
    return (*this);
}
