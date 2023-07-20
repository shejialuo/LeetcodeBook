#include <limits>
#include <vector>
using namespace std;

int combinationSum4(vector<int> &nums, int target) {
  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int j = 0; j <= target; ++j) {
    for (int i = 0; i < nums.size(); ++i) {
      if (j >= nums[i] &&
          dp[j] < numeric_limits<int>::max() - dp[j - nums[i]]) {
        dp[j] += dp[j - nums[i]];
      }
    }
  }
  return dp.back();
}
