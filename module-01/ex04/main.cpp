#include <iostream>
#include <fstream>
#include <string>

// ./ex_04 filename str1 str2
int	main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "wrong arguments" << std::endl;
		return (1);
	}
	std::ifstream	inFile(argv[1]);
	std::string		inFileName(argv[1]);
	std::string		oldString(argv[2]);
	std::string		newString(argv[3]);
	std::string		resString;

	if (inFile.is_open()) {
		char	c;
		while (inFile.get(c)) {
			resString += c;
			if (resString.length() >= oldString.length()) {
				if (!resString.compare(resString.length() - oldString.length(), oldString.length(), oldString)) {
					resString.erase(resString.length() - oldString.length());
					resString += newString;
				}
			}
		}
		inFile.close();
	} else {
		std::cout << "unable to open " << inFileName << std::endl;
		return (1);
	}

	std::string		outFileName(argv[1]);
	outFileName += ".replace";
	std::ofstream	outFile(outFileName.c_str());
	if (outFile.is_open()) {
		outFile << resString;
		outFile.close();
	} else {
		std::cout << "could not create outfile." << std::endl;
		return (1);
	}
	return (0);
}
