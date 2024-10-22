#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <ostream>
# include <string>

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		int	getGrade(void) const;
		const std::string & getName(void) const;
		
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(Form &form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what(void) const throw() { return ("Grade too high."); };
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what(void) const throw() { return ("Grade too low."); };
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & burocrat);

#endif
