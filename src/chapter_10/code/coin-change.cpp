#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount) {

  vector<int> dp(amount + 1, numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 0; i < coins.size(); ++i) {
    for (int j = coins[i]; j <= amount; ++j) {
      if (dp[j - coins[i]] != numeric_limits<int>::max()) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
  }

  return dp.back() == numeric_limits<int>::max() ? -1 : dp.back();
}
