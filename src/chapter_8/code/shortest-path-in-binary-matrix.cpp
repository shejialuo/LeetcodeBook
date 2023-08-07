#include <queue>
#include <utility>
#include <vector>
using namespace std;

bool isValid(int i, int j, int m, int n) {
  return i >= 0 && i < m && j >= 0 && j < n;
}

vector<vector<int>> directions{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
};

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  vector<vector<bool>> isVisited(m, vector<bool>(n, false));

  int length = 0;
  queue<pair<int, int>> qu{};

  if (grid[0][0] == 0) {
    isVisited[0][0] = true;
    qu.push(make_pair(0, 0));
  }
  while (!qu.empty() && !isVisited[m - 1][n - 1]) {
    int size = qu.size();
    for (int k = 0; k < size; k++) {
      auto &&[i, j] = qu.front();

      for (auto &&direction : directions) {
        int nextI = i + direction[0];
        int nextJ = j + direction[1];

        if (isValid(nextI, nextJ, m, n) && grid[nextI][nextJ] == 0 &&
            !isVisited[nextI][nextJ]) {
          isVisited[nextI][nextJ] = true;

          qu.push(make_pair(nextI, nextJ));
        }
      }
      qu.pop();
    }
    length++;
  }

  return isVisited[m - 1][n - 1] ? length + 1 : -1;
}
