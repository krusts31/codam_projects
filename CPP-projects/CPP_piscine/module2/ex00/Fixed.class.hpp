#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed(Fixed const & a);			//Copy Construcotr
		~Fixed();				//deconstrucotr
		Fixed();				//Default constructor
		int	getRawBits(void) const;		//returns the raw value of the fixed point value
		void	setRawBits(int const raw);	//set the raw value of the fixed point value
		Fixed &	operator=(Fixed const & src);	//operator overload

	private:
		int			_fixedPointValue;
		static const int	_numberOfFractionalBits = 8;
};


#endif
