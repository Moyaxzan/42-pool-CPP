#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap {
	public:
		ClapTrap(std::string ct_name);
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);
		~ClapTrap();

		std::string		getName(void);
		unsigned int	getHitPoints(void);
		unsigned int	getEnergyPoints(void);
		unsigned int	getAttackDamages(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif // !CLAPTRAP_HPP
