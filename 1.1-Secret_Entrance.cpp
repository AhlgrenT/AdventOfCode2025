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
  int dial = 50;
  int zeroes = 0;
	  
  while (std::getline(input, line)) {
    if (line.empty()) continue;
    
    int value = std::stoi(line.substr(1)); 

    if (line.at(0) == 'L') {
    	value = 100 - value;
    }
 
    dial = (dial + value) % 100;
    if (dial == 0) zeroes++;
  }
	
  std::cout << zeroes << std::endl;
  input.close();
  
  return 0;
}

