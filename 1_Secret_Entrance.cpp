#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {

    std::ifstream input(argv[1]);

	if (!input) {
		  std::cerr << "Could not open file!" << std::endl;
		  return 1;
	}
	
	std::string line;
	
	while (std::getline(input, line)) {
    std::cout << line << std::endl;
	}
	
	input.close();
	return 0;
}

