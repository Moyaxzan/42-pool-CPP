#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"


class	PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		add(void);
		int		search(void);

	private:
		Contact	contacts[8];
		int		nb_of_contacts;
};

#endif
