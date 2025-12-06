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

//i rangen.
/*
,64164836-64292066,
l = 8
1
2: 64 ? 64...
   65 ? X
3: 8 % 3 != 0...
4: 6416 ? 6416.... +1 +1 +1... och kolla alltid om i rangen
5: ÖVER HÄLFTEN 

*/



int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
long long int tot = 0;
  if (!input) {
  
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }
  
  // look first digit
  // check if second digit is a repeat 
  // if not then check
  //1-1
  //2-2
  //3-3
  //if tot is biger than full skip it
  

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
    
    std::string start = start_stop[0];
    std::string stop = start_stop[1];
    long long int nStart = std::stoll(start);
    long long int nStop = std::stoll(stop);
    
    long long int current = nStart;
    //MAIN LOOP
    std::unordered_set<long long int> seen;
    //std::cout << "\n"; //CHECK THAT CHUNK IS POSSIBLE
    while(current <= nStop) {  
      //LOOP REPEAT SIZE
      //std::cout << "Checking: " << current << std::endl;
      std::string current_s = std::to_string(current);
      int len = current_s.length();
      for(int i = 1; i <= len/2; i++){
        std::string sub_str = current_s.substr(0,i);
        std::string ret_string = "";
        while(ret_string.length() < len) {
          ret_string += sub_str;
          //std::cout << "Building:"<< sub_str << std::endl;
        }
        
        long long int repeated = std::stoll(ret_string);
        if ((repeated <= nStop) && (repeated >= nStart)) {
          if (seen.find(repeated) == seen.end()) {   // not found
            seen.insert(repeated);
            std::cout << "Added " << repeated << "\n";
            tot += repeated;
          }
        }
      }
      current++;
    }
  }
  

  
    
    
  std::cout << tot << std::endl;
  
  input.close();
  
  return 0;
}



