#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

int ans = 0;
void helper(vector<int> &nums, int i, int sum, int target) {
  if (i == nums.size()) {
    if (sum == target) {
      ans++;
    }
  } else {
    helper(nums, i + 1, sum + nums[i], target);
    helper(nums, i + 1, sum - nums[i], target);
  }
}

int dynamicProgramming(vector<int> &nums, int target) {
  int sum = accumulate(nums.cbegin(), nums.cend(), 0);
  if ((sum + target) % 2 != 0) {
    return 0;
  }
  if (sum < abs(target)) {
    return 0;
  }

  int weight = (sum + target) / 2;

  vector<int> dp(weight + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = weight; j >= nums[i]; j--) {
      dp[j] += dp[j - nums[i]];
    }
  }
  return dp.back();
}

int findTargetSumWays(vector<int> &nums, int target) {
  // helper(nums, 0, 0, target);
  // return ans;
  return dynamicProgramming(nums, target);
}
