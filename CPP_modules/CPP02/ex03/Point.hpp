/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:02:05 by gfantech          #+#    #+#             */
/*   Updated: 2023/05/02 12:08:42 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const	Fixed x;
	const	Fixed y;
public:
	Point();
	Point(const Fixed &n1, const Fixed &n2);
	Point(const Point &a);
	Point &operator= (const Point &a);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
	void	setX(Fixed n);
	void	setY(Fixed n);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
