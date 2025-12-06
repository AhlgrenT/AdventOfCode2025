#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  if (!input) {
  
  std::cerr << "Could not open file!" << std::endl;
    return 1;
  }
  
  std::string line;
  long int res = 0;
  
  while(std::getline(input, line)) {
    int first_pos = 0;
    long int line_total = 0;
    int last_pos = 11;
    int len = line.length();
    
    for (int i = 0; i < 12; i++){
      int curr = first_pos;
      
      for(int j = first_pos; j < len-last_pos; j++){
        if (line[j] > line[curr]) {
            curr = j;
        }
      }
      res += (line[curr] - '0') * std::pow(10, last_pos);
      first_pos = curr + 1;
      last_pos -= 1;
    }
  }
  
  std::cout << "Result: " << res << std::endl;
  input.close();
  
  return 0;
}



