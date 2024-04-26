#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"


class	PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

	private:
		Contact	contacts[8];
};

#endif
