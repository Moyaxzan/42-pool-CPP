#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource& other);
		MateriaSource&	operator=(MateriaSource& other);
		~MateriaSource(void);

		void deleteStock(void);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria*	_stock[4];
};


#endif
