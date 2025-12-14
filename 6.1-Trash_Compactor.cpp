#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  if (!input) {
  
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }

  // Globals
  long long int tot = 0;
  std::string line;
  std::vector<long long int> results;
  std::vector<bool> addition;
  
  // Populate operator vector
  while(std::getline(input, line)) {  
    if (line[0] != '*' && line[0] != '+') continue; 
    std::stringstream ss(line);
    char a;
    while (ss >> a) {
      if (a == '+') {
        addition.push_back(true);
      } else {
        addition.push_back(false);
      }
    } 
  }
  
  // Reset file reader
  input.clear();
  input.seekg(0, std::ios::beg);
  
  bool first = true;
  while(std::getline(input, line)) { 
    if (line[0] == '*' || line[0] == '+') break;
    std::stringstream ss(line);
    long long int a;
    int i = 0;
    while(ss >> a) {
      if (first) {
        results.push_back(a);
      } else {
        if(addition[i]) {
          results[i] += a;
        } else {
          results[i] *= a;
        }
      }
      i++;
    }
    first = false;
  }
  
  //Calculate total
  for(int i = 0; i < results.size(); i++) {
    tot += results[i];
  }
    
  std::cout << "Result: " << tot << std::endl;
  
  input.close();
  
  return 0;
}
