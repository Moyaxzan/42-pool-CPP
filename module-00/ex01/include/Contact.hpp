#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class	Contact {

	public:
		Contact(void);
		int			fill_contact(void);
		void		print_contact(void);
		std::string	get_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		~Contact(void);

	private:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
};

#endif
