#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums) {
  int j = nums.size() - 1;
  int i = j - 1;

  while (i >= 0) {
    if (nums[i] < nums[j]) {
      break;
    }
    i--;
    j--;
  }

  if (i < 0) {
    reverse(nums.begin(), nums.end());
    return;
  }

  for (int k = nums.size() - 1; k >= j; k--) {
    if (nums[k] > nums[i]) {
      swap(nums[k], nums[i]);
      break;
    }
  }

  reverse(nums.begin() + j, nums.end());
}
