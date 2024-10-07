#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal {
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		virtual ~Animal();

		std::string	getType(void) const;
		virtual void		makeSound(void) const = 0;
		virtual std::string	get_idea(int index) const = 0;
		virtual void	set_idea(int index, std::string idea) = 0;
	protected:
		std::string	_type;
};

#endif // !ANIMAL_HPP
