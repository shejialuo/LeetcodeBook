#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> ans(n, vector<int>(n, 0));

  int num = 1;
  int widthIndex = n - 1, heightIndex = n - 1;
  int i = 0;
  while (i <= heightIndex && i <= widthIndex) {

    for (int k = i; k <= widthIndex; k++) {
      ans[i][k] = num++;
    }

    for (int k = i + 1; k <= heightIndex; k++) {
      ans[k][widthIndex] = num++;
    }

    if (i < heightIndex) {
      for (int k = widthIndex - 1; k >= i; k--) {
        ans[heightIndex][k] = num++;
      }
    }

    if (i < widthIndex) {
      for (int k = heightIndex - 1; k > i; k--) {
        ans[k][i] = num++;
      }
    }

    i++;
    widthIndex--;
    heightIndex--;
  }

  return ans;
}
