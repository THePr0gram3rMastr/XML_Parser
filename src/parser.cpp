#include <iostream>
#include <fstream>
#include <string>

#define NO_SYMBOLS_REMAIN "SYM/NULL"

class Parser {
private:
	std::ifstream file;
	std::string input;
public:
	Parser() {
	}

	Parser(const char* in_file, const char* arg) {
		file.open(in_file);
		file >> input;

		if (file.fail()) {
			std::cout << "Error opening file...." << std::endl;
		}

		if ((!file.fail()) && arg == "/c") {
			syntax_check(input, "");
			display(in_file);
		}
	}

	bool syntax_check(std::string input, std::string str_to_find) {

		std::string tag;

		int str_MIN{};
		int str_MAX = 0;

		if (input != "Lol") {

			for (int i = 1; input[i - 1] != '>'; i++) {
				if (input[i - 1] == '<') {
					tag += input[i - 1];
					for (int j = i; input[j - 1] != '>'; j++) {
						tag += input[j];
						str_MAX = j + 1;
					}
				}
			}

		}
		else {
			tag = NO_SYMBOLS_REMAIN;
		}

		str_to_find = tag;

		if (str_MAX != 0) {
			str_MIN = (str_MAX - str_to_find.size());
		} else {
			str_MIN = NULL;
		}

		std::size_t found = input.find(str_to_find);

		if (found != std::string::npos) {

			input.erase(str_MIN, str_MAX);

			syntax_check(input, str_to_find);
		}
		else {
			std::cout << "No symbols remain" << std::endl;
			return false;
		}

		return true;
	}

	void display(const char* in_file) {

		file >> input;

		for (int i = 0; i < input.length(); i++) {
			if ((input[i] != '<') && (input[i] != '>')) {
				std::cout << input[i];
			} else if ((input[i] == '<')) {
				for (int j = i; input[j] != '>'; j++) {
					input[j] = 0x00;
				}
			}
		}
	}
};

int main(int argc, char** argv) {

	std::cin >> *argv;

	std::cout << std::endl;

	const char* file = *argv;

	Parser parse(file, "/c");

	return 0;
}