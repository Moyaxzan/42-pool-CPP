#ifndef FIXED_HPP
# define FIXED_HPP

//first cannonical class
class Fixed {
	public:
		Fixed();	//constructor
		Fixed(const Fixed &other);	// copy constructor
		Fixed &operator=(const Fixed &other);	//assignment operator
		~Fixed();	//destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedValue;
		static const int	_fractBits = 8;
};

#endif // !FIXED_HPP
