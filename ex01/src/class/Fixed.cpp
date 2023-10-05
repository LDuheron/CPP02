/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:07:13 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/05 12:21:38 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_bits(8);

// Constructor -----------------------------------------------------------------

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = src._value;
}

Fixed::Fixed( int const src)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = src << _bits;
}

Fixed::Fixed( float const src)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(src * (1 << _bits));
}


// Destructor ------------------------------------------------------------------

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// Overload  -------------------------------------------------------------------

Fixed &				Fixed::operator=(Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs._value;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &lhs, Fixed const &rhs)
{
	lhs << rhs.toFloat();
	return lhs;
}

// Accessors  ------------------------------------------------------------------

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// Functions  ------------------------------------------------------------------

int		Fixed::toInt( void ) const
{
	return (this->_value >> _bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << _bits));
}
