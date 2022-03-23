#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Railgun.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Meseeks.hpp"
#include "Character.hpp"
#include <iostream>

int	main()
{
	Character* dude = new Character("dude");
	std::cout << *dude;
	Enemy *b = new RadScorpion();
	Enemy *d = new SuperMutant();
	Enemy *m = new Meseeks();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();
	AWeapon *rg = new Railgun();

	dude->equip(pr);
	std::cout << *dude;
	dude->equip(pf);
	std::cout << *dude;
	dude->attack(b);
	std::cout << *dude;
	dude->attack(b);
	dude->attack(d);
	dude->attack(d);
	dude->equip(pr);
	dude->attack(d);
//	dude->attack(d);	Sefaults. to prove that the objecr b was deleted
	dude->recoverAP();
	dude->recoverAP();
	dude->recoverAP();
	dude->recoverAP();
	dude->recoverAP();
	dude->attack(d);
	dude->attack(d);
	dude->attack(d);
	dude->attack(d);
//	dude->attack(d);	Segfaults. to prove that the object d was deleted
	std::cout << *dude;
	dude->equip(rg);
	dude->attack(m);
	dude->attack(m);
	delete(pr);
	delete(pf);
	delete(rg);
	delete(dude);
	return (0);
}
