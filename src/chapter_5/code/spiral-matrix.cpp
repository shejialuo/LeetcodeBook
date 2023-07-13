#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  vector<int> ans{};

  int heightIndex = matrix.size() - 1;
  int widthIndex = matrix[0].size() - 1;

  int i = 0;
  while (i <= heightIndex && i <= widthIndex) {

    for (int k = i; k <= widthIndex; k++) {
      ans.push_back(matrix[i][k]);
    }

    for (int k = i + 1; k <= heightIndex; k++) {
      ans.push_back(matrix[k][widthIndex]);
    }

    // Do not add repeating row.
    if (i < heightIndex) {
      for (int k = widthIndex - 1; k >= i; k--) {
        ans.push_back(matrix[heightIndex][k]);
      }
    }

    // Do not add repeating column
    if (i < widthIndex) {
      for (int k = heightIndex - 1; k > i; k--) {
        ans.push_back(matrix[k][i]);
      }
    }
    i++;

    heightIndex--;
    widthIndex--;
  }

  return ans;
}
