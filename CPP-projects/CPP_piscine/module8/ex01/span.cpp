#include "span.hpp"

span::span(){}

span::span(unsigned int N)
{
	_N.reserve(N);
}

span::~span(){}

span::span(span const & src)
{
	*this = src;
}

span & span::operator=(span const & src)
{
	_N.assign(src._N.begin(), src._N.end());
	return *this;
}

unsigned int	span::shortestSpan(void)
{
	if (this->_N.size() < 2)
		throw (spanNoContentException());
	if (this->_N.size() == 2)
		return (longestSpan());

	unsigned int	size = _N.size();
	std::vector<unsigned int>	values;
	std::vector<int>		hold;
	hold.reserve(2);
	values.reserve(size);
	sort(_N.begin(), _N.end());
	std::vector<int>::const_iterator it2;
	std::vector<int>::const_iterator next;

	it2 = this->_N.begin();
	for (; it2 < this->_N.end(); it2++)
	{
		next = it2 + 1;
		hold.push_back(*it2);
		hold.push_back(*next);
		int min = *min_element(hold.begin(), hold.end());
		int max = *max_element(hold.begin(), hold.end());
		values.push_back(max - min);
		if (next < this->_N.end())
			hold.clear();
		else
			break ;
	}
	unsigned int	min;
	min = *min_element(values.begin(), values.end());
	return (min);
}

unsigned int	span::longestSpan(void)		
{
	if (this->_N.size() < 2)
		throw spanNoContentException();
	int min = *min_element(this->_N.begin(), this->_N.end());
	int max = *max_element(this->_N.begin(), this->_N.end());
	return (max - min);
}

void		span::addNumber(int value)
{
	if (_N.capacity() > _N.size())
		_N.push_back(value);
	else
		throw (spanOverSizeException());
}

void		span::display_vector(void)
{
	std::vector<int>::iterator it = _N.begin();
	sort(_N.begin(), _N.end());
	for (; it != _N.end(); ++it)
		std::cout << *it << " " << std::endl;
}

span::spanOverSizeException::spanOverSizeException(void) {}
span::spanOverSizeException::spanOverSizeException(spanOverSizeException const & src) { *this = src; }
span::spanOverSizeException::~spanOverSizeException(void) throw() {}
span::spanOverSizeException const &span::spanOverSizeException::operator=(spanOverSizeException const & rhs) { (void)rhs; return *this; }
const char* span::spanOverSizeException::what() const throw()
{
	return "span Over Size";
}

span::spanNoContentException::spanNoContentException(void) {}
span::spanNoContentException::spanNoContentException(spanNoContentException const & src) { *this = src; }
span::spanNoContentException::~spanNoContentException(void) throw() {}
span::spanNoContentException const &span::spanNoContentException::operator=(spanNoContentException const & rhs) { (void)rhs; return *this; }
const char* span::spanNoContentException::what() const throw()
{
	return "span No Content";
}
