#include <string>
#include <vector>
using namespace std;

vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int m, int n) {
  return i >= 0 && i < m && j < n && j >= 0;
}

bool existHelper(vector<vector<char>> &board, int i, int j, int index,
                 string &word) {
  if (board[i][j] != word[index]) {
    return false;
  }

  if (index == word.size() - 1) {
    return true;
  }

  int m = board.size(), n = board[0].size();

  const char c = board[i][j];
  board[i][j] = '*';

  for (auto &&direction : directions) {
    int nextI = i + direction[0];
    int nextJ = j + direction[1];
    if (isValid(nextI, nextJ, m, n) && board[nextI][nextJ] != '*') {
      bool result = existHelper(board, nextI, nextJ, index + 1, word);
      if (result) {
        return true;
      }
    }
  }
  board[i][j] = c;
  return false;
}

bool exist(vector<vector<char>> &board, string word) {

  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      if (existHelper(board, i, j, 0, word))
        return true;
    }
  }
  return false;
}
