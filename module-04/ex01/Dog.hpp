#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		~Dog();

		std::string	get_idea(int index) const;
		void		set_idea(int index, std::string idea);
	private:
		Brain	*_brain;
};

#endif // !DOG_HPP
