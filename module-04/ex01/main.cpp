#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	const WrongAnimal*	wcat = new WrongCat();
	const WrongAnimal*	wani = new WrongAnimal();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound(); //will output the Wrong cat sound!
	std::cout << wani->getType() << " " << std::endl;
	wani->makeSound();

	return (0);
}
