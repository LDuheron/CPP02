/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:10:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/03 21:23:01 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(s);
	Fixed	c;

	c = b;
	
	std::cout << a.getRawBits() << std:endl;
	std::cout << b.getRawBits() << std:endl;
	std::cout << c.getRawBits() << std:endl;

	return (0);
}