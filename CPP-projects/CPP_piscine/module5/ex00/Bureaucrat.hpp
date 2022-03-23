#ifndef Bureaucrat_CLASS_H
# define Bureaucrat_CLASS_H
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
public:

/*
**	Exceptions
*/

class	GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
		GradeTooLowException(void);
		~GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const &src);
		GradeTooLowException	&operator=(GradeTooLowException const &src);
};

class	GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
		GradeTooHighException(void);
		~GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const &src);
		GradeTooHighException	&operator=(GradeTooHighException const &src);
};

/*
**	Exceptions end
*/


/*
**	Member functions 
*/
	void	gradeUp(void);
	void	gradeDown(void);

/*
**	End of member functions
*/


/*
**	Construcotrs
*/

	Bureaucrat(std::string const & name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);

/*
**	End of Construcotrs
*/



/*
**	Operator overloads
*/

	Bureaucrat & operator=(Bureaucrat const & src);

/*
**	End of operator overloads
*/



/*
**	Getters
*/

	std::string	getName(void) const;
	int		getGrade(void) const;

/*
**	End of Getters
*/

private:

	Bureaucrat();		//Default constructor

/*
**	Varibles
*/

	std::string const	 _name;
	int			_grade;

/*
**	Enf of Varibles
*/
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &beura);
#endif
