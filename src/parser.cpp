#include <iostream>
#include <fstream>
#include <string>

class Parser {
private:
	std::ifstream file;
	std::string input;

	std::string test_string = "<note>Lol";
public:
	Parser() {
	}

	Parser(const char* in_file, const char* arg) {
		file.open(in_file);

		if (file.fail()) {
			std::cout << "Error opening file...." << std::endl;
		}

		if ((!file.fail()) && arg == "/c") {
			syntax_check(test_string, "<note>");
			//display(in_file);
		}
	}

	bool syntax_check(std::string input, std::string str_to_find) {

		//file >> input;

		std::size_t found = input.find(str_to_find);

		if (found != std::string::npos) {

			input.erase(0, 5); //fixed erasure position

			std::cout << "FOUND!" << std::endl;

			syntax_check(input, str_to_find);
		}
		else {
			std::cout << "Syntax Error: " << "No closing tag on " << str_to_find << std::endl;
			return false;
		}

		/*	
			if a substring is discovered containing < >

			assign that substring to a global std::string

			remove that section from primary string

			if substring != global std::string
				PRINT ERROR	!
				return false

			call syntax_sheck(input)

			return true

			//ALTERNATE SOLUTION

			call syntax_check(input, string_to_find)



		*/







		return true;
	}

	void display(const char* in_file) {

		file >> input;

		const int buffer_alloc_size = input.length();

		char* buffer = new char[buffer_alloc_size];

		for (int i = 0; i < input.length(); i++) {
			*(buffer + i) = input[i];

			//std::cout << i << ". " << *(buffer + i) << std::endl;
		}

		for (int i = 0; i < input.length(); i++) {
			if ((input[i] != '<') && (input[i] != '>')) {
				std::cout << input[i];
			} else if ((input[i] == '<')) {
				for (int j = i; input[j] != '>'; j++) {
					input[j] = 0x00;
				}
			}
		}

		std::string name = "Donald J Jump";

		std::size_t found = name.find("Jump");

		if (found != std::string::npos) {
			std::cout << "Found at " << found << std::endl;
		}



	}
};

int main(int argc, char** argv) {

	std::cin >> *argv;

	const char* file = *argv;

	Parser parse(file, "/c");

	return 0;
}