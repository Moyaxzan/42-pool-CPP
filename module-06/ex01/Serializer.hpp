#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>

typedef struct s_data {
	int value;
}	Data;

class Serializer {
	public :

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer& other);
		Serializer& operator=(Serializer& other);
		~Serializer(void);

};

#endif
