#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) {
	{
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	}


	ICharacter* player1 = new Character("Player1");
	ICharacter* player2 = new Character("Player2");

	IMateriaSource* Msource = new MateriaSource();
	Msource->learnMateria(new Ice());
	Msource->learnMateria(new Cure());

	AMateria* tmp;
	tmp = Msource->createMateria("ice");
	player1->equip(tmp);
	player1->use(0, *player2);
	player1->unequip(-1);
	player1->unequip(4);
	AMateria* todel = player1->getMateria(0);
	player1->unequip(0);
	delete todel;
	tmp = Msource->createMateria("cure");
	player1->equip(tmp);
	tmp = Msource->createMateria("cure");
	player1->equip(tmp);
	tmp = Msource->createMateria("cure");
	player1->equip(tmp);
	tmp = Msource->createMateria("cure");
	player1->equip(tmp);
	player1->use(1, *player2);
	player1->use(2, *player2);
	player1->use(3, *player2);
	player1->use(4, *player2);

	delete player2;
	delete player1;
	delete Msource;
	return 0;
}
