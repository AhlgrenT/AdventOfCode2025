#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void printMatrix(const std::vector<std::string>& v) {
    for (const auto& s : v) {
        std::cout << s << "\n";
    }
}

int laser(std::vector<std::string>& v, int row, int col){
  if(row >= v.size()) return 1;
  char curr = v[row][col];
  
  if(curr =='^'){
    return laser(v, row, col-1) + laser(v, row, col+1);
  } else if (curr == '.') {
    v[row][col] = '|';
    return laser(v, row+1, col);
  } else {
    return 1;
  }
}

int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  if (!input) {
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }

  std::string line;
  std::vector<std::string> matrix;
  int splits = 0;
  
  // Populate matrix vector
  while(std::getline(input, line)) {  
    matrix.push_back(line);
  }
  
  //Find S and start recursive function.
  for(int i = 0; i < matrix[0].size(); i++) {
    if(matrix[0][i] == 'S') {
      splits = laser(matrix, 1, i);
      break;
    }  
  }
  
  printMatrix(matrix);
  std::cout << "Result is: " << splits-1 << std::endl;
  
  input.close();
  
  return 0;
}
