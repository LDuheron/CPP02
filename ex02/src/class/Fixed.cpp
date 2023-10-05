/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:07:13 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/05 02:35:51 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_bits(8);

// Constructor -----------------------------------------------------------------

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( const Fixed & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	// if (!src)
	// 	src = 0;
	// else

	// std::cout << "src in copy constructor : " << src._value << std::endl;
	this->_value = src._value;
	// std::cout << "in copy constructor : " << this->_value << std::endl;
}

Fixed::Fixed( int const src)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = src;
}

Fixed::Fixed( float const src)
{
	// std::cout << "Float constructor called" << std::endl;
	// std::cout << "in float constructor : " << src << std::endl;

	this->_value =(roundf(src * (1 << _bits)));
	// std::cout << "in float constructor : " << this->_value << std::endl;
}


// Destructor ------------------------------------------------------------------

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// int		Fixed::toInt(float src )
// {
// 	// src = src._value >> _bits;
// 	return (src >> _bits);
// }

// Overload  -------------------------------------------------------------------

Fixed &				Fixed::operator=(Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs._value;
	}
	std::cout << this->_value << std::endl;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

// Operateurs de comparaison ---------------------------------------------------

bool		Fixed::operator>(Fixed const & rhs ) const
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value > rhs._value)
		return (true);
	return (false);
}

bool			Fixed::operator<(Fixed const & rhs ) const
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value < rhs._value)
		return (true);
	return (false);
}

bool			Fixed::operator>=(Fixed const & rhs )
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value >= rhs._value)
		return (true);
	return (false);
}

bool			Fixed::operator<=(Fixed const & rhs )
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value <= rhs._value)
		return (true);
	return (false);
}

bool			Fixed::operator==(Fixed const & rhs )
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value == rhs._value)
		return (true);
	return (false);
}

bool			Fixed::operator!=(Fixed const & rhs )
{
	// std::cout << "Comparison operator called" << std::endl;
	if (this->_value != rhs._value)
		return (true);
	return (false);
}


// Operateurs arithmetique -----------------------------------------------------

Fixed &				Fixed::operator+(Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value += rhs._value;
	}
	return *this;
}

Fixed &				Fixed::operator-(Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value -= rhs._value;
	}
	return *this;
}

Fixed &				Fixed::operator*(Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	// std::cout << "lhs : " << this->_value << std::endl;
	// std::cout << "rhs : " << rhs << std::endl;
	if ( this != &rhs )
	{
		this->_value = this->_value * rhs._value;
	}
	// std::cout << "this value : " << this->_value << std::endl;
	return *this;
}

Fixed &				Fixed::operator/(Fixed const & rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value /= rhs._value;
	}
	return *this;
}

// Operateurs incrementation et decrementation --------------------------------

Fixed &				Fixed::operator++() // Prefix incrementation ++a
{
	// std::cout << "Copy assignment operator called" << std::endl;
	++this->_value;
	return *this;
}

Fixed				Fixed::operator++( int ) // Postfix incrementation a++
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value++;
	return *this;
}

Fixed &				Fixed::operator--()
{
	// std::cout << "Copy assignment operator called" << std::endl;
	--this->_value;
	return *this;
}

Fixed				Fixed::operator--( int )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value--;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


std::ostream	&operator<<(std::ostream &lhs, Fixed const &rhs)
{
	lhs << rhs.toFloat();
	return lhs;
}

// Accessors  ------------------------------------------------------------------

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member functon called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member functon called" << std::endl;
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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

const Fixed	& Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

const Fixed	& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}
