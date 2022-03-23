#include "Human.hpp"
#include <iostream>

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "SHOUTING ON " << target << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	int	act;
	void (Human:: *actions[3])(std::string const & target) =
	{
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	
	act = ("meleeAttack" == action_name) ? 0 :
		("rangedAttack" == action_name) ? 1 :
		("intimidatingShout" == action_name) ? 2
		: throw "Invalid action.";
	(this->*actions[act])(target);
}
