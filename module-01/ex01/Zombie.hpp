#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {
	public:
		Zombie();
		void	announce(void);
		void	set_name(std::string name);
		~Zombie();

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif // !ZOMBIE_HPP
