#include <algorithm>
#include <vector>
using namespace std;

int trapMemoized(vector<int> &height) {
  vector<int> leftSuccessors(height.size(), 0);
  vector<int> rightSuccessors(height.size(), 0);

  int leftMax = height[0];
  for (int i = 1; i < height.size(); i++) {
    leftMax = max(leftMax, height[i]);
    leftSuccessors[i] = leftMax;
  }

  int rightMax = height.back();
  for (int i = height.size() - 2; i >= 1; i--) {
    rightMax = max(rightMax, height[i]);
    rightSuccessors[i] = rightMax;
  }

  int totalWater = 0;
  for (int i = 0; i < height.size(); i++) {
    if (i == 0 || i == height.size() - 1) {
      continue;
    }
    totalWater += min(rightSuccessors[i], leftSuccessors[i]) - height[i];
  }
  return totalWater;
}

int trap(vector<int> &height) { return trapMemoized(height); }
