#ifndef DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//TODO:: create inheritance with Scav and Frag Traps
class DiamondTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

	private:

};

#endif // !DIAMONDTRAP_HPP
