#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal	&operator=(const WrongAnimal &other);
		~WrongAnimal();

		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif // !WRONGANIMAL_HPP
