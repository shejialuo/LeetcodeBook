#include <numeric>
#include <vector>
using namespace std;

bool canPartition(vector<int> &nums) {
  int sum = accumulate(nums.cbegin(), nums.cend(), 0);
  if (sum % 2 != 0) {
    return false;
  }

  int target = sum / 2;

  vector<bool> dp(target + 1, false);
  dp[0] = true;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = target; j >= nums[i]; j--) {
      if (dp[j - nums[i]]) {
        dp[j] = true;
      }
    }
  }
  return dp.back();
}
