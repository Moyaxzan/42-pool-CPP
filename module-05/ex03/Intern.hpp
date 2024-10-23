#ifndef INTERN_HPP
# define INTERN_HPP
#include <exception>
# include <string>
# include "AForm.hpp"

class Intern {
	public :
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm* makeForm(const std::string name, const std::string target);

		class UnknownForm : public std::exception {
			public :
				virtual const char *what(void) const throw() {
					return ("Form name not recognized by Intern");
				}
		};
};

#endif
