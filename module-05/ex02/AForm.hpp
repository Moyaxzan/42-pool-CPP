#ifndef FORM_HPP
# define FORM_HPP
#include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm(void);
		AForm(const std::string name, int minSignGrade, int minExecGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		std::string const & getName(void) const;
		bool getIsSigned(void) const;
		int getMinSignGrade(void) const;
		int getMinExecGrade(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;

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
		virtual void _doExecute(void) const = 0;

		std::string const _name;
		bool _isSigned;
		int _minSignGrade;
		int _minExecGrade;
};

std::ostream& operator<<(std::ostream& os, Form const & form);

#endif
