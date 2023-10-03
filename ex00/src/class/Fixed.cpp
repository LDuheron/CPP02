/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:07:13 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/03 21:25:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor
Fixed::Fixed()
{
	std::cout << "Constructor called";
	setRawBits(8);
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Constructor called";
	setRawBits(8);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called";
}

// Overload
Fixed &				Fixed::operator=( Fixed const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}

int	Fixed::getRawBits( void )
{
	std::cout << "getRawBits member functon called" << std::endl;
	return (_bits);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member functon called" << std::endl;
	_bits = raw;
}
