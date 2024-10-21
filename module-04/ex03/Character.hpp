#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
	public:
		Character(std::string const name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character(void);

		std::string const &	getName(void) const;
		void	deleteInventory(void);
		void	equip(AMateria *m);
		void	unequip(int index);
		void	use(int index, ICharacter& target);
		AMateria*	getMateria(int index);

	private:
		AMateria*	_invetory[4];
		std::string	_name;
};

#endif
