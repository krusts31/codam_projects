#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include <iostream>

int main()
{
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "testing if the squad works fine" << std::endl;
	std::cout << "********************************************************************************" << std::endl;
	int	x;

	x = 0;
//Creating units
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* bob1 = new TacticalMarine;
	ISpaceMarine* jim1 = new AssaultTerminator;
	ISpaceMarine* bob2 = new TacticalMarine;
	ISpaceMarine* jim2 = new AssaultTerminator;
	TacticalMarine* bobTM = new TacticalMarine;
	AssaultTerminator* jimAT = new AssaultTerminator;

//	ISpaceMarine* jimCopy = jim2;
//	ISpaceMarine	*jimClone = jim->clone();
//	ISpaceMarine	*bobClone = bob->clone();
//	jim1 = bob2;

//Creating squad
	Squad vlc;
//Inserting units in squad
	x = vlc.push(bob);
	x = vlc.push(jim);
	x = vlc.push(bob1);
	x = vlc.push(jim1);
	x = vlc.push(bob2);
	x = vlc.push(vlc.getUnit(3));
	x = vlc.push(vlc.getUnit(-20));
	x = vlc.push(jim2);
	x = vlc.push(bobTM);
	x = vlc.push(jimAT);

//	x = vlc.push(jimCopy);
//	x = vlc.push(jimClone);
//	x = vlc.push(bobClone);

//Displaynig units
	for (int i = 0; i < vlc.getCount(); ++i)
	{
		std::cout << "Solidner nr:" <<  x << std::endl;
		ISpaceMarine* cur = vlc.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
		x--;
	}
	std::cout << "********************************************************************************" << std::endl;
//Creating more units
	ISpaceMarine* bobx = new TacticalMarine;
	ISpaceMarine* jimx = new AssaultTerminator;
	ISpaceMarine* bobx1 = new TacticalMarine;
	ISpaceMarine* jimx1 = new AssaultTerminator;
	std::cout << "********************************************************************************" << std::endl;
//Creating a 2nd squad
	Squad vlc1;
	x = vlc1.push(bobx);
	x = vlc1.push(jimx);
	x = vlc1.push(bobx1);
	x = vlc1.push(jimx1);
	std::cout << "creating a new squad and initialazing it with an operator overload " << std::endl;
	std::cout << "********************************************************************************" << std::endl;
	vlc1 = vlc;	//	testing if operator overload works and there is a deep copy
	std::cout << "********************************************************************************" << std::endl;
	ISpaceMarine* jimx3 = new AssaultTerminator;
	std::cout << "********************************************************************************" << std::endl;
	x = vlc1.push(jimx3);
	x = vlc1.getCount();
	for (int i = 0; i < vlc1.getCount(); ++i)
	{
		std::cout << "Solidner nr:" <<  x << std::endl;
		ISpaceMarine* cur = vlc1.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
		x--;
	}

	std::cout << "********************************************************************************" << std::endl;
	std::cout << "creating a new squad and initialaizing in with a copy constructor " << std::endl;
	std::cout << "********************************************************************************" << std::endl;
	Squad vlc2(vlc1);
	std::cout << "********************************************************************************" << std::endl;
	x = vlc2.getCount();
	ISpaceMarine* jimx4 = new AssaultTerminator;
	std::cout << "********************************************************************************" << std::endl;
	x = vlc2.push(jimx4);
	for (int i = 0; i < vlc2.getCount(); ++i)
	{
		std::cout << "Solidner nr:" <<  x << std::endl;
		ISpaceMarine* cur = vlc2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
		x--;
	}
	return (0);
}
