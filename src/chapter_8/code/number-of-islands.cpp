#include <vector>
using namespace std;

// Defines the direction for easy compute
vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j, int m, int n) {
  return i >= 0 && i < m && j >= 0 && j < n;
}

void dfsSolutionHelper(vector<vector<char>> &grid, int i, int j, int m, int n) {
  if (isValid(i, j, m, n) && grid[i][j] == '1') {
    grid[i][j] = '0';
    for (auto &&direction : directions) {
      int nextI = i + direction[0];
      int nextJ = j + direction[1];
      dfsSolutionHelper(grid, nextI, nextJ, m, n);
    }
  }
}

int dfsSolution(vector<vector<char>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  int ans = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        ans++;
        dfsSolutionHelper(grid, i, j, m, n);
      }
    }
  }
  return ans;
}

int numIslands(vector<vector<char>> &grid) { return dfsSolution(grid); }
