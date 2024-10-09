#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria {
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(AMateria &other);
		~AMateria(void);

		std::string	const & getType(void) const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	protected:
		std::string	_type;
};

#endif
