#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

//first cannonical class
class Fixed {
	public:
		Fixed(void);				//default constructor
		Fixed(const int integer);	//constructor with int
		Fixed(const float floating);	//constructor with float
		Fixed(const Fixed &other);	// copy constructor

		Fixed	&operator=(const Fixed &other);	//assignment operator

		bool	operator<(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++(void);	//pre increment
		Fixed	operator++(int);	//post increment
		Fixed	&operator--(void);	//pre decrement
		Fixed	operator--(int);	//post decrement

		static Fixed const	&max(const Fixed &a, const Fixed &b);
		static Fixed const	&min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);

		~Fixed();	//destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedValue;
		static const int	_nbFractBits = 8;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif // !FIXED_HPP
