#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int	main()
{
	MateriaSource	src;
	src.learnMateria(new Ice());
	src.learnMateria(new Ice());
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	src.learnMateria(new Ice());
	//src.learnMateria(new Ice());

	Character	dude("dude");
	AMateria 	*tmp;

	tmp = src.createMateria("ice");
	dude.equip(tmp);
	tmp = src.createMateria("cure");
	dude.equip(tmp);
	tmp = src.createMateria("ice");
	dude.equip(tmp);
	tmp = src.createMateria("ice");
	dude.equip(tmp);
//	dude.unequip(3); //this will have a memleak, becasue subject does not sepcifay deleting AMateria upon unequip function
	

//	dude.unequip(1);
	std::cout << "***************************************************" << std::endl;
	std::cout << "testing DUDE!" << std::endl;
	Character	bob("bob");
	tmp = src.createMateria("ice");
	bob.equip(tmp);
	dude.use(0, bob);
	dude.use(1, bob);
	dude.use(2, bob);
	dude.use(2, bob);
	dude.use(2, bob);
	dude.use(3, bob);
	dude.use(100, bob);
	dude.use(-1, bob);
	std::cout << "***************************************************" << std::endl;

	MateriaSource	src1;
	src1.learnMateria(new Ice());
	std::cout << "***************************************************" << std::endl;
	std::cout << "testing DUDE!" << std::endl;
	Character	guy("Guy");
	tmp = src1.createMateria("cure");
//operator overload test
	src1 = src;
	tmp = src1.createMateria("cure");
	guy.equip(tmp);
	tmp = src1.createMateria("ice");
	guy.equip(tmp);
	guy.use(0, bob);
	guy.use(1, bob);
	guy = dude;
	guy.use(3, bob);
	std::cout << "***************************************************" << std::endl;

//copy	construcotr test

	std::cout << "***************************************************" << std::endl;
	std::cout << "testing guy from copy construcotr!" << std::endl;
	MateriaSource	src2(src);

	Character	man(guy);

	man.use(0, bob);
//	man.unequip(1);
	man.use(1, bob);
	man.use(2, bob);
	man.use(3, bob);
	std::cout << "***************************************************" << std::endl;

	return (0);
}
