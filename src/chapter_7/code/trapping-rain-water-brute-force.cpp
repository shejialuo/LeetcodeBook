

#include <algorithm>
#include <vector>
using namespace std;

int trapBruteForce(vector<int> &height) {
  int totalWater = 0;
  for (int i = 0; i < height.size(); i++) {
    if (i == 0 || i == height.size() - 1) {
      continue;
    }

    int leftSuccessor = height[i];
    int rightSuccessor = height[i];

    for (int j = 0; j < i; j++) {
      leftSuccessor = max(leftSuccessor, height[j]);
    }

    for (int j = i + 1; j < height.size(); j++) {
      rightSuccessor = max(rightSuccessor, height[j]);
    }

    if (leftSuccessor != height[i] && rightSuccessor != height[i]) {
      totalWater += min(leftSuccessor, rightSuccessor) - height[i];
    }
  }
  return totalWater;
}

int trap(vector<int> &height) { return trapBruteForce(height); }
