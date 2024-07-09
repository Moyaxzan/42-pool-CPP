#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	public:
		Point(void);						//constructor
		Point(const Fixed x, const Fixed y);	//fixed constructor
		Point(const Point &other);			//copy const
		Point &operator=(const Point &other);	//assignment op
		~Point(void);						//destructor
		

		Fixed	get_x() const;
		Fixed	get_y() const;
		void	set_x(Fixed const x);
		void	set_y(Fixed const y);


	private:
		Fixed	_x;
		Fixed	_y;
	
};

Fixed	fixedAbs(const Fixed a);
Fixed	triangleArea(const Point a, const Point b, const Point c);
bool	insideTriangle(const Point p, const Point a, const Point b, const Point c);
#endif
