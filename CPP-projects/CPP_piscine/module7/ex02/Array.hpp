#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <iostream>

template <typename T>

class	Array
{
public:
//construcotrs
	Array<T>() : _array(NULL), _n(0) {}

	Array<T>(unsigned int n) :_array(new T[n]()), _n(n) {} 

	~Array<T>()
	{
		if (this->_array != NULL)
			delete[] this->_array;
		return ;
	}

	Array<T>& operator=(Array const &src)
	{
		unsigned int	i;

		i = 0;
		if (this == &src)
			return (*this);
		if (this->_array != NULL)
			delete[] this->_array;
		this->_array = new T[src._n];
		this->_n = src._n;
		while (i != _n)
		{
			this->_array[i] = src._array[i];
			i++;
		}
		return (*this);
	}

	Array<T>(Array const & src)
	{
		*this = src;
	}

	class	OutOfTheLimits : public std::exception
	{
	public:
		OutOfTheLimits(void) { }
		OutOfTheLimits(const OutOfTheLimits &) { }
		~OutOfTheLimits(void) throw() { }
		OutOfTheLimits& operator = (OutOfTheLimits const &src) { (void)src;}
		virtual const char *what() const throw()
		{
			return "Element is out of the limits";
		}
	};

	unsigned int	size()			const
	{
		return (this->_n);
	}

	T&	operator[](unsigned int	i)	const
	{
		if (i >= this->_n)
			throw (OutOfTheLimits());
		return (this->_array[i]);
	}
private:
	T*		_array = NULL;
	unsigned int	_n;
};
#endif
