#ifndef DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, FragTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		void	attack(std::string target);
		void	whoAmI();
	private:
		std::string	name;
};

#endif // !DIAMONDTRAP_HPP
