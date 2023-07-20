#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLISTwoLoop(vector<int> &nums) {
  vector<int> dp(nums.size(), 1);
  int result = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    result = max(result, dp[i]);
  }
  return result;
}

int lengthOfLIS(vector<int> &nums) { return lengthOfLISTwoLoop(nums); }
