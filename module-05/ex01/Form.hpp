#ifndef FORM_HPP
# define FORM_HPP
#include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form(void);
		Form(const std::string name, int minSignGrade, int minExecGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		std::string const & getName(void) const;
		bool getIsSigned(void) const;
		int getMinSignGrade(void) const;
		int getMinExecGrade(void) const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what(void) const throw() { return ("Grade too low."); };
		};

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what(void) const throw() { return ("Grade too high."); };
		};

		class FormAlreadySigned : public std::exception {
			public :
				virtual const char* what(void) const throw() { return ("Form was already signed."); };
		};

	private:
		std::string const _name;
		bool _isSigned;
		int _minSignGrade;
		int _minExecGrade;
};

std::ostream& operator<<(std::ostream& os, Form const & form);

#endif
