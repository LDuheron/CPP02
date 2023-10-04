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

		bool		operator>(Fixed const & rhs );
		bool		operator<(Fixed const & rhs );
		bool		operator>=(Fixed const & rhs );
		bool		operator<=(Fixed const & rhs );
		bool		operator==(Fixed const & rhs );
		bool		operator!=(Fixed const & rhs );

		static int &  	min(int a, int b);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream &			operator<<( std::ostream & lhs, Fixed const & rhs );

#endif
