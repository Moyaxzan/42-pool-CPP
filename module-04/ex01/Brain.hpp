#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain {
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		std::string	get_idea(int index) const;
		void	set_idea(int index, std::string idea);
	private:
		std::string	_ideas[100];
};

#endif // !BRAIN_HPP
