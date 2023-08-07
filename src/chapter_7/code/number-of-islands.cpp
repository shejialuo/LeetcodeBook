

#include <vector>
using namespace std;

// Defines the direction for easy compute
vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Define the Disjoint set
class DisjointSet {
private:
  vector<int> data;

public:
  int counter{};

  DisjointSet(int n) {
    data.resize(n);
    for (int i = 0; i < n; ++i) {
      data[i] = i;
    }
  }

  int root(int i) {
    while (data[i] != i) {
      data[i] = data[data[i]];
      i = data[i];
    }
    return i;
  }

  void connect(int i, int j) {
    int rootI = root(i);
    int rootJ = root(j);
    if (rootI != rootJ) {
      data[rootI] = rootJ;
      counter--;
    }
  }

  bool isConnect(int i, int j) { return root(i) == root(j); }
};

bool isValid(int i, int j, int m, int n) {
  return i >= 0 && i < m && j >= 0 && j < n;
}

int unionFindSolution(vector<vector<char>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  DisjointSet set{m * n};

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        set.counter++;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        for (auto &&direction : directions) {
          int nextI = i + direction[0];
          int nextJ = j + direction[1];

          if (isValid(nextI, nextJ, m, n) && grid[nextI][nextJ] == '1') {
            set.connect(i * n + j, nextI * n + nextJ);
          }
        }
      }
    }
  }

  return set.counter;
}

int numIslands(vector<vector<char>> &grid) { return unionFindSolution(grid); }
