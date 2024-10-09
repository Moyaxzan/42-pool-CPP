#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <string>

class AMateria;

class ICharacter {
	public:
		ICharacter(void);
		ICharacter(const ICharacter& other);
		ICharacter& operator=(const ICharacter& other);
		virtual	~ICharacter(void) {};
	
		virtual std::string const &	getName() const = 0;
		virtual void	equip(AMateria *m);
		virtual void	unequip(int index) = 0;
		virtual void	use(int index, ICharacter& target) = 0;
};

#endif
