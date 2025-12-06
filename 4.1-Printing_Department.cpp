#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {

  std::ifstream input(argv[1]);
  if (!input) {
  
  std::cerr << "Could not open file!" << std::endl;
    return 1;
  }
 
  std::vector<std::string> grid;
  std::string line;
  int res = 0;
  
  // TODO: Set row and col sizes automatically
  int rows = 139; 
  int cols = 139;
  char dRow[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
  char dCol[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

  // Populate matrix
  while(std::getline(input, line)) {
    grid.push_back(line); 
  }
  
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(grid[i][j] != '@') continue;
      int neighours = 0;
      for(int z = 0; z < 8; z++) {
        // OOB check:
        if(i+dRow[z] > rows-1 || i+dRow[z] < 0 || j + dCol[z] > cols-1 || j + dCol[z] < 0) continue;

        if ((grid[i + dRow[z]][j + dCol[z]]) == '@') {
          neighours++;
        }  
      }  
      if (neighours < 4) res++;
    }
  }
  
  std::cout << "Result: " << res << std::endl;
  input.close();
  
  return 0;
}



