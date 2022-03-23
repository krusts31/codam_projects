#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H
#include <iostream>

class Fixed
{
	public:

		Fixed(Fixed const & a);			//Copy Construcotr
		Fixed(int const param);			//Parameter Constructor
		Fixed(float const param);		//Parameter Constructor
		~Fixed();				//deconstrucotr
		Fixed();				//Default constructor

		float	toFloat(void)		const;
		int	toInt(void)		const;
		int	getRawBits(void)	const;
		void	setRawBits(int const raw);	//set the raw value of the fixed point value
		
		Fixed &	operator=(Fixed const & src);	//operator overload

		bool	operator>(Fixed const & src)	const;	//operator overload
		bool	operator<(Fixed const & src)	const;	//operator overload
		bool	operator>=(Fixed const & src)	const;	//operator overload
		bool	operator<=(Fixed const & src)	const;	//operator overload
		bool	operator==(Fixed const & src)	const;	//operator overload
		bool	operator!=(Fixed const & src)	const;	//operator overload

		Fixed	operator+(Fixed const & src);	//operator overload
		Fixed	operator-(Fixed const & src);	//operator overload
		Fixed	operator/(Fixed const & src);	//operator overload
		Fixed	operator*(Fixed const & src);	//operator overload

		Fixed	operator++(int);		//post increment
		Fixed	operator++();			//pre increment
		Fixed	operator--(int);
		Fixed	operator--();

		static Fixed const &max(Fixed const &x, Fixed const &y);
		static Fixed const &min(Fixed const &x, Fixed const &y);
		static Fixed &max(Fixed &x, Fixed &y);
		static Fixed &min(Fixed &x, Fixed &y);

	private:

		int _fixedPointValue;
		static const int _numberOfFractionalBits = 8;
};


std::ostream &operator<<(std::ostream &out, Fixed const &_fixedPointValue);
Fixed const &min(Fixed const &x, Fixed const &y);
Fixed const &max(Fixed const &x, Fixed const &y);
Fixed &min(Fixed &x, Fixed &y);
Fixed &max(Fixed &x, Fixed &y);

#endif
