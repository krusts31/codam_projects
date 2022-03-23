#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	return ;
}
TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
	return ;
}
TacticalMarine & TacticalMarine::operator=(TacticalMarine const & src)
{
	(void)src;
	return *this;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = src;
}

void	TacticalMarine::battleCry()		const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void	TacticalMarine::meleeAttack()		const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

void	TacticalMarine::rangedAttack()		const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

TacticalMarine	*TacticalMarine::clone() const
{
	return (new TacticalMarine);		//can I create this on the stack
}
