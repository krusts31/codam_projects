#include "FragTrap.hpp"
#include <iostream>

int	main()
{
//testing varibles
	FragTrap FR4GTP;
	std::cout << "Testing FragTrap varibles" << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "curent hp "<< FR4GTP.gethp() << std::endl;
	std::cout << "maxhp "<< FR4GTP.getmaxHp() << std::endl;
	std::cout << "curent ep "<< FR4GTP.geteP() << std::endl;
	std::cout << "curent maxep "<< FR4GTP.getmaxEp() << std::endl;
	std::cout << "curent levle "<< FR4GTP.getlevle() << std::endl;
	std::cout << "melee damage "<< FR4GTP.getmeleeDamage() << std::endl;
	std::cout << "ranaged damage "<< FR4GTP.getrangeAttackDamage() << std::endl;
	std::cout << "armour "<< FR4GTP.getarmour() << std::endl;
	std::cout << "name "<< FR4GTP.getname() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
//testing membre functions
	std::cout << "Testing FragTrap Member functions" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
	FR4GTP.rangedAttack("Badass!");
	FR4GTP.meleeAttack("Badass!");
//energy testing
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Energy testing" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.energyPack(999);
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.energyPack(112);
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.energyPack(999);
	std::cout << FR4GTP.geteP() << std::endl;
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	FR4GTP.vaulthunter_dot_exe("Badass!");
	std::cout << FR4GTP.geteP() << std::endl;
//hp testing
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Hitpoint testing" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.beRepaired(100);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.beRepaired(0);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.takeDamage(10);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.beRepaired(5);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.takeDamage(90);
	FR4GTP.takeDamage(5);
	FR4GTP.takeDamage(4);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.takeDamage(10);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.takeDamage(100);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.takeDamage(100);
	std::cout << FR4GTP.gethp() << std::endl;
	FR4GTP.beRepaired(420);
	std::cout << FR4GTP.gethp() << std::endl;
	return (0);
}
