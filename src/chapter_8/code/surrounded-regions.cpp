#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValidForDFS(int i, int j, int m, int n) {
  return i >= 1 && i < m - 1 && j >= 1 && j < n - 1;
}

void dfsSolutionHelper(vector<vector<char>> &board, int i, int j, int m, int n,
                       bool isBoarder = false) {
  if (!isBoarder) {
    board[i][j] = '0';
  }
  for (int k = 0; k < 4; ++k) {
    int nextI = i + dirs[k][0];
    int nextJ = j + dirs[k][1];
    if (isValidForDFS(nextI, nextJ, m, n) && board[nextI][nextJ] == 'O') {
      dfsSolutionHelper(board, nextI, nextJ, m, n);
    }
  }
}
void dfsSolution(vector<vector<char>> &board) {
  int m = board.size();
  int n = board[0].size();

  for (int i = 0; i < m; ++i) {
    if (board[i][0] == 'O') {
      dfsSolutionHelper(board, i, 0, m, n, true);
    }
    if (board[i][n - 1] == 'O') {
      dfsSolutionHelper(board, i, n - 1, m, n, true);
    }
  }

  for (int j = 0; j < n; ++j) {
    if (board[0][j] == 'O') {
      dfsSolutionHelper(board, 0, j, m, n, true);
    }
    if (board[m - 1][j] == 'O') {
      dfsSolutionHelper(board, m - 1, j, m, n, true);
    }
  }

  for (int i = 1; i < m - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (board[i][j] == '0') {
        board[i][j] = 'O';
      } else if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
    }
  }
}

void solve(vector<vector<char>> &board) { dfsSolution(board); }
