#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void calculate_row(std::vector<std::vector<long int>>& v, int row){
  for(int i = 0; i < v[0].size(); i++) {

    long int curr = v[row][i];
    int next_row = row + 1;
    int left  = i - 1;
    int right = i + 1;
    
    if(curr != 0 && curr != -1) {
      if(v[next_row][i] == -1) {
        v[next_row][left] += curr;
        v[next_row][right] += curr;        
      } else {
        v[next_row][i] += curr;
      }
    }
  }
}

int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  if (!input) {
    std::cerr << "Could not open file!" << std::endl;
    return 1;
  }

  std::string line;
  std::vector<std::string> char_matrix;
  long int tot = 0;
  
  // Populate char matrix
  while(std::getline(input, line)) {  
    char_matrix.push_back(line);
  }
  
  // Char to small, need int vector
  std::vector<std::vector<long int>> int_matrix;
  for(int i = 0; i < char_matrix.size(); i++) {
    std::vector<long int> row;
    for(int j = 0; j < char_matrix[i].size(); j++) {
      if(char_matrix[i][j] == '.') {
        row.push_back(0);
      } else if (char_matrix[i][j] == 'S'){
        row.push_back(1);
      } else if (char_matrix[i][j] == '^') {
        row.push_back(-1);
      }
    }
    int_matrix.push_back(row);
  }

  // Calculate
  for(int i = 0; i < int_matrix.size()-1; i++) {
    calculate_row(int_matrix, i);
  }

  // Add grand total
  for(int i = 0; i < int_matrix[int_matrix.size()-1].size(); i++) {
    tot += int_matrix[int_matrix.size()-1][i];
  }
  
  std::cout << "Result is: " << tot << std::endl;
  
  input.close();
  return 0;
}
