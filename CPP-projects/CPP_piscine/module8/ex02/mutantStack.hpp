#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# define container c
# include <stack>

template <typename T>
class MutantStack : public std::stack< T, std::deque<T> > 
{
public:
//constructor
	MutantStack(): std::stack<T>() {}
	MutantStack(std::stack<T> const &src): std::stack<T>(src) 
	{	*this = src;	}
	MutantStack(MutantStack const &src): std::stack<T>(src) 
	{	*this = src;	}
//deconstructor
	virtual ~MutantStack() {}
//operator overloads
	using std::stack<T>::operator=;

//meber functions
	typedef typename std::deque<T>::iterator		iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;
	typedef typename std::deque<T>::const_iterator		const_iterator;

	iterator		begin()	{	return (this->container.begin());	}
	iterator		end()	{	return (this->container.end());		}
	reverse_iterator	rbegin(){	return (this->container.rbegin());	}
	reverse_iterator	rend()	{	return (this->container.rend());	}
};
#endif 
