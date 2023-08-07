#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int rowStart = 0, rowEnd = matrix.size();
  while (rowStart < rowEnd) {
    int rowMid = (rowStart + rowEnd) / 2;
    if (matrix[rowMid][0] == target) {
      return true;
    } else if (matrix[rowMid][0] > target) {
      rowEnd = rowMid;
    } else {
      rowStart = rowMid + 1;
    }
  }

  rowStart--;
  if (rowStart < 0) {
    return false;
  }

  int colStart = 0, colEnd = matrix[0].size();
  while (colStart < colEnd) {
    int colMid = (colStart + colEnd) / 2;
    if (matrix[rowStart][colMid] == target) {
      return true;
    } else if (matrix[rowStart][colMid] > target) {
      colEnd = colMid;
    } else {
      colStart = colMid + 1;
    }
  }
  return false;
}
