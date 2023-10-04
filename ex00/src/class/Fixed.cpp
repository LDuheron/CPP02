/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:07:13 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/04 18:44:34 by lduheron         ###   ########.fr       */
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
	// this->_value = src._value;
	this->_value = src.getRawBits();
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
		this->_value = rhs.getRawBits();
	}
	return *this;
}



// Functions  ------------------------------------------------------------------

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
