#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

  dp[0][1] = -prices[0];
  dp[0][0] = 0;

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = max(dp[i - 1][1], -prices[i]);
  }

  return dp.back()[0];
}
