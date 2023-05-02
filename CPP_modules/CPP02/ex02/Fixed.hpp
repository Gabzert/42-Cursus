/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:17:09 by gfantech          #+#    #+#             */
/*   Updated: 2023/04/24 12:27:52 by gfantech         ###   ########.fr       */
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
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &a);
	Fixed &operator= (const Fixed &a);
	bool operator< (const Fixed &a) const;
	bool operator> (const Fixed &a) const;
	bool operator<= (const Fixed &a) const;
	bool operator>= (const Fixed &a) const;
	bool operator== (const Fixed &a) const;
	bool operator!= (const Fixed &a) const;
	Fixed &operator++ ();
	Fixed &operator++ (int);
	Fixed &operator-- ();
	Fixed &operator-- (int);
	Fixed &operator+ (const Fixed &a);
	Fixed &operator- (const Fixed &a);
	Fixed &operator* (const Fixed &a);
	Fixed &operator/ (const Fixed &a);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &max( Fixed &first, Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);


    friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};
