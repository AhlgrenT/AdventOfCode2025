#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s, char splitter) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;
    
  while (std::getline(ss, item, splitter)) {
    result.push_back(item);
  }
  return result;
}

long long all_nines(long long n) {
    long long result = 0;
    long long tmp = n;
    if (tmp == 0) return 9; // handle 0 specially
    while (tmp > 0) {
        result = result * 10 + 9; // append a 9 for each digit
        tmp /= 10;                // remove one digit
    }
    return result;
}

int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);

  if (!input) {
  
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }
  
  
  unsigned long int tot = 0;
  std::string line;
  std::getline(input, line);
  std::cout << line << std::endl;
  auto range = split(line, ',');
  /*for (const auto& f : range) {
      auto start_stop = split(f, '-');
  }*/
  for (const auto& f : range) {
    auto start_stop = split(f, '-');

    std::cout << "f = [" << f << "]\n";
    for (const auto& part : start_stop) {
        std::cout << "   part = [" << part << "]\n";
    }
    

    if ((start_stop[0].length() == start_stop[1].length()) && (start_stop[0].length() % 2 == 1)) {
      std::cout << "EVERYTHING UNEVEN!" << std::endl;
      continue;
    }
    
    //new approach: just take half. And check first number in left part
    //if that number mirrored is in the range -> OK, and increase and try again
    //if not then we quit
    
    
    std::string start_half = start_stop[0].substr(0, start_stop[0].length()/2);
    long long start_half_int = std::stoll(start_half);
    long long start_full_int = std::stoll(start_stop[0]);
   
    std::string end_half = start_stop[1].substr(0, start_stop[1].length()/2);
    long long end_full_int = std::stoll(start_stop[1]);
    long long end_half_int = std::stoll(end_half);
    if(start_half_int > end_half_int)
    std::cout << "sa " << start_half << std::endl;
    if(start_half_int > end_half_int) {
      end_half_int = all_nines(end_half_int);
    }
    std::cout << "sb " << end_half << std::endl;
    
    while(start_half_int <= end_half_int) {
      std::cout << "start half int: " << start_half_int << std::endl;
      /*if (start_stop[0].length() % 2 == 1) {
        std::cout << "UNEVEN!" << std::endl;
              start_half_int += 1;
      start_half = std::to_string(start_half_int);
        continue;
      }*/
      //std::string half = start_string.substr(0, start_string.length()/2);
      long long mirror = std::stoll(start_half + start_half);
      std::cout << "mirriros is:" << mirror << std::endl;
      //if mirror is in the range
      if ((mirror <= end_full_int) && (mirror >= start_full_int)) {
        std::cout << "Match:" << mirror << std::endl;
        tot += mirror;
        
      }
      start_half_int += 1;
      start_half = std::to_string(start_half_int);
      
    }
    std::cout << tot << std::endl;
    
    //get length
    //get pointer to start and end
    
    //reqs for repeating:
    //  if sequenc starts with 1000
    //  we know that a repeating must repeat the first part.
    //  check length -> first part.
  }
  

  
    
    
  //std::cout << result << std::endl;
  
  input.close();
  
  return 0;
}



