#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

# define SCAVTRAP_HP 100
# define SCAVTRAP_EP 50
# define SCAVTRAP_AD 20

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string st_name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(std::string target);
		void	guardGate(void);
};

#endif // !SCAVTRAP_HPP
