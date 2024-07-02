#ifndef WEAPON_HPP

# define WEAPON_HPP
# include <string>

class Weapon{
	public:
		Weapon(std::string type);
		std::string	getType(void);
		void		setType(std::string type);
		~Weapon();

	private:
		std::string	_type;
};

#endif // !WEAPON_HPP
