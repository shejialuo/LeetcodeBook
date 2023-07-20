#include <vector>
using namespace std;

int robHelper(vector<int> &nums, int index, int recent) {
  if (index < nums.size()) {
    if (index == recent + 1) {
      return robHelper(nums, index + 1, recent);
    } else {
      return max(robHelper(nums, index + 1, index) + nums[index],
                 robHelper(nums, index + 1, recent));
    }
  }
  return 0;
}

int rob(vector<int> &nums) {
  return robHelper(nums, 0, -2);
}