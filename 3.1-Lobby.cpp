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
  int res = 0;

  while(std::getline(input, line)) {
    int largest_pos = 0;
    
    int len = line.length();
    for(int i = 0; i < len-1; i++) {
      if (line[i] > line[largest_pos]) {
        largest_pos = i;
      }  
    }
    
    int second_pos = largest_pos+1;
    for(int i = largest_pos+1; i < len; i++) {     
      if (line[i] > line[second_pos]) {
        second_pos = i;
      }
    }

    int tot = ((line[largest_pos] - '0') * 10) + (line[second_pos] - '0');
    res += tot; 
  }
  
  std::cout << "Result: " << res << std::endl;
  input.close();
  
  return 0;
}



