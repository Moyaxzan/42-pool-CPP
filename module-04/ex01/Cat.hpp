#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		~Cat();

		std::string	get_idea(int index) const;
		void		set_idea(int index, std::string idea);
	private:
		Brain	*_brain;
};

#endif // !CAT_HPP
