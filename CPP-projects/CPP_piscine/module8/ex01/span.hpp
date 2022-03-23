#ifndef span_CLASS_H
# define span_CLASS_H
# include <iterator>
# include <algorithm>
# include <vector>
# include <climits>
# include <list>
# include <iostream>

class span
{
public:
//construcotrs
	span(unsigned int N);
	~span();
	span(span const & src);
//operator overloads
	span & operator=(span const & src);
//member functions
	void	addNumber(int	value);
	template <typename T>
	void			addNumber(T first, T last) {
		if (std::distance(first, last) + this->_N.size() > this->_N.capacity())
			throw (spanOverSizeException()); 
		this->_N.insert(this->_N.end(), first, last);
	}
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	class spanOverSizeException : public std::exception
	{
		public: 
			spanOverSizeException(void);
			spanOverSizeException(spanOverSizeException const & src);
			virtual ~spanOverSizeException(void) throw();
			spanOverSizeException const &operator=(spanOverSizeException const & rhs);
			virtual const char* what() const throw();
	};
	class spanNoContentException : public std::exception
	{
		public:
			spanNoContentException(void);
			spanNoContentException(spanNoContentException const & src);
			virtual ~spanNoContentException(void) throw();
			spanNoContentException const &operator=(spanNoContentException const & rhs);
			virtual const char* what() const throw();
	};
	void display_vector(void);
private:
	std::vector<int>	_N;
	span();
};
#endif
