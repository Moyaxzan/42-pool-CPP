#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#define SIZE 40 //pair value for loops in main

int main()
{
	{
		Cat *cat = new Cat();

		cat->set_idea(4, "meow moew *il fait beau dehors*");
		cat->set_idea(53, "meow *croquettes*");
		cat->set_idea(97, "meow meow meow *oula... un chien...*");

		std::cout << cat->get_idea(4) << std::endl;
		std::cout << cat->get_idea(53) << std::endl;
		std::cout << cat->get_idea(97) << std::endl;
		std::cout << cat->get_idea(-1) << std::endl; // invalid index

		std::cout << std::endl;
		std::cout << std::endl;

		delete cat;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl << std::endl;
	std::cout << std::endl;
	{
		Animal *dog = new Dog();

		dog->set_idea(2, "woof woof *c'est une balle ca ?*");
		dog->set_idea(34, "wooooooof *donne moi ce baton !!*");
		dog->set_idea(71, "wof wof wof *mhhhhh ca sent bon*");
		dog->set_idea(-27, "woof *c'est mon canape*"); // invalid index
		dog->set_idea(92, "woof *c'est mon canape*");

		std::cout << dog->get_idea(3) << std::endl; //unset index (...nothing...)
		std::cout << dog->get_idea(2) << std::endl;
		std::cout << dog->get_idea(34) << std::endl;
		std::cout << dog->get_idea(71) << std::endl;
		std::cout << dog->get_idea(-88) << std::endl; // invalid index
		std::cout << dog->get_idea(92) << std::endl;
		
		std::cout << std::endl;
		std::cout << std::endl;
		delete dog;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl << std::endl;
	std::cout << std::endl;
	{
		Animal *array[SIZE];

		for (int i = 0; i < SIZE / 2; i++) {
			array[i] = new Cat();
		}
		std::cout << std::endl << std::endl;
		for (int i = SIZE / 2; i < SIZE; i++) {
			array[i] = new Dog();
		}
		std::cout << std::endl << std::endl;
		for (int i = 0; i < SIZE; i++) {
			array[i]->makeSound();
		}
		std::cout << std::endl << std::endl;
		for (int i = 0; i < SIZE; i++) {
			delete array[i];
		}
	}
	return (0);
}
