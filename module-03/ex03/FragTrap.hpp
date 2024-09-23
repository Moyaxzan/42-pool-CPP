#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

# define FRAGTRAP_HP 100
# define FRAGTRAP_EP 100
# define FRAGTRAP_AD 30

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(std::string ft_name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void	attack(std::string target);
		void	highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP
