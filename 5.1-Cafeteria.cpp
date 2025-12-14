#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

std::vector<std::string> split(const std::string& s, char splitter) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;
    
  while (std::getline(ss, item, splitter)) {
    result.push_back(item);
  }
  return result;
}

int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  long long int tot = 0;
  if (!input) {
  
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }

  std::vector<long long int> start;
  std::vector<long long int> end;

  std::string line;
  bool first_part = true;
  
  while(std::getline(input, line)) {  
    if (line.empty()) break;
    auto range = split(line, '-');
    start.push_back(std::stoll(range[0]));
    end.push_back(std::stoll(range[1]));
    
  }
  
  while(std::getline(input, line)) {
    std::cout << "Second part: " << line << "\n";
    long long int ingredient = std::stoll(line);
    for(int i = 0; i < start.size(); i++) {
      if(ingredient <= end[i] && ingredient >= start[i]) {
        tot++;
        break;
      }
    }
  }

  
    
    
  std::cout << "Total: " << tot << std::endl;
  
  input.close();
  
  return 0;
}
