#include <queue>
#include <utility>
#include <vector>
using namespace std;

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> ans(n, vector<int>(m, 0));

  queue<pair<int, int>> qu{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 0) {
        for (int k = 0; k < 4; ++k) {
          int nextI = i + dirs[k][0];
          int nextJ = j + dirs[k][1];
          if (isValid(nextI, nextJ, n, m) && mat[nextI][nextJ] == 1 &&
              ans[nextI][nextJ] == 0) {
            ans[nextI][nextJ] = 1;
            qu.push(make_pair(nextI, nextJ));
          }
        }
      }
    }
  }

  while (!qu.empty()) {
    auto &&front = qu.front();

    for (int k = 0; k < 4; ++k) {
      int nextI = front.first + dirs[k][0];
      int nextJ = front.second + dirs[k][1];

      if (isValid(nextI, nextJ, n, m) && mat[nextI][nextJ] == 1 &&
          ans[nextI][nextJ] == 0) {
        ans[nextI][nextJ] = ans[front.first][front.second] + 1;
        qu.push({nextI, nextJ});
      }
    }
    qu.pop();
  }
  return ans;
}
