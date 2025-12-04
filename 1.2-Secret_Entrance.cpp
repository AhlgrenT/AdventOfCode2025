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
  bool dir;
	  
  while (std::getline(input, line)) {
    if (line.empty()) continue;
    
    int value = std::stoi(line.substr(1)); 
    int distance_to_0;
    
    if (line.at(0) == 'L') {
    	distance_to_0 = dial;
    	dir = false;
    } else {
      distance_to_0 = 100 - dial;
      dir = true;
    }
    
    if(value >= distance_to_0) {
      value -= distance_to_0;
      if (distance_to_0 != 0) {
        zeroes += 1;
      }
    } else {
      dir ? dial = dial + value : dial = dial - value;
      continue; 
    }

    // Calculate how many full-turns starting from 0
    zeroes += value / 100;
    value = value % 100;
    
    // Set dial to final value
    if (dir == true) {
      dial = value;
    } else {
      dial = 100 - value;
    }
  }
	
  std::cout << zeroes << std::endl;
  input.close();
  
  return 0;
}

