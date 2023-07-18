#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(int k, vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));

  for (int i = 0; i < 2 * k + 1; i++) {
    if (i % 2 == 0) {
      dp[0][i] = 0;
    } else {
      dp[0][i] = -prices[0];
    }
  }

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = dp[i - 1][0];
    for (int j = 1; j < 2 * k + 1; j++) {
      if (j % 2 != 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
      }
    }
  }

  return *max_element(dp.back().begin(), dp.back().end());
}
