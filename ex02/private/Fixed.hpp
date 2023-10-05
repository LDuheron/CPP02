#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static int const	_bits;

	public:

		Fixed();
		Fixed( Fixed const & src );

		Fixed( int const src );
		Fixed( float const src );

		~Fixed();

		Fixed &		operator=( Fixed const & rhs );
	
		Fixed &		operator+(Fixed const & rhs );
		Fixed &		operator-(Fixed const & rhs );
		Fixed &		operator*(Fixed const & rhs );
		Fixed &		operator/(Fixed const & rhs );
	
		Fixed &		operator++();
		Fixed		operator++( int );
		Fixed &		operator--();
		Fixed		operator--( int );

		bool		operator>(Fixed const & rhs ) const ;
		bool		operator<(Fixed const & rhs ) const ;
		bool		operator>=(Fixed const & rhs );
		bool		operator<=(Fixed const & rhs );
		bool		operator==(Fixed const & rhs );
		bool		operator!=(Fixed const & rhs );

		Fixed	&	min(Fixed &a, Fixed &b);
		Fixed	&	max(Fixed &a, Fixed &b);
		const Fixed	 & min(Fixed const & a, Fixed const & b);
		const Fixed	& max(Fixed const  &a, Fixed const & b);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt(float src );

		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream &			operator<<( std::ostream & lhs, Fixed const & rhs );

#endif
