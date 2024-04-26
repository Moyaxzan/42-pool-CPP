#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class	Contact {

	public:
		Contact(void);
		int	fill_contact(void);
		~Contact(void);

	private:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
};

#endif
