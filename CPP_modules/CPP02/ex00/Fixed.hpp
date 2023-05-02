/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:17:09 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/20 10:49:57 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int value;
	static const int bits = 8;
	
public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed & operator= (const Fixed &a);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
