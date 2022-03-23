#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include "ScavTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(std::string name);
	~SuperTrap();
	SuperTrap &operator=(const SuperTrap &rhs);
	void		meleeAttack(std::string const &target);
	void		rangedAttack(std::string const &target);
private:
	SuperTrap();
};

#endif
