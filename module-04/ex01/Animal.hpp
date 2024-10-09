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
		void		makeSound(void) const;
		
		virtual std::string	get_idea(int index) const;
		virtual void		set_idea(int index, std::string idea);
	protected:
		std::string	_type;
};

#endif // !ANIMAL_HPP
