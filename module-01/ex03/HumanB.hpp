#ifndef HUMANB_HPP

# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
		~HumanB();

	private:
		std::string	_name;
		Weapon	*_weapon;
};

#endif // !HUMANA_HPP
