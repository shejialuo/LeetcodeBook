#include <vector>
using namespace std;

const unsigned int M = 1000000007;

int checkRecord(int n) {
  vector<vector<int>> dp(n + 1, vector<int>(6, 0));

  dp[0][5] = 1;

  for (int i = 1; i <= n; i++) {

    dp[i][4] = (dp[i][4] + dp[i - 1][0]) % M;

    dp[i][0] = (dp[i][0] + dp[i - 1][1]) % M;
    dp[i][4] = (dp[i][4] + dp[i - 1][1]) % M;

    dp[i][4] = (dp[i][4] + dp[i - 1][2]) % M;
    dp[i][5] = (dp[i][5] + dp[i - 1][2]) % M;

    dp[i][2] = (dp[i][2] + dp[i - 1][3]) % M;
    dp[i][4] = (dp[i][4] + dp[i - 1][3]) % M;
    dp[i][5] = (dp[i][5] + dp[i - 1][3]) % M;

    dp[i][1] = (dp[i][1] + dp[i - 1][4]) % M;
    dp[i][4] = (dp[i][4] + dp[i - 1][4]) % M;

    dp[i][4] = (dp[i][4] + dp[i - 1][5]) % M;
    dp[i][3] = (dp[i][3] + dp[i - 1][5]) % M;
    dp[i][5] = (dp[i][5] + dp[i - 1][5]) % M;
  }

  int ans = 0;
  for (int i = 0; i < dp.back().size(); i++) {
    ans = (ans + dp.back()[i]) % M;
  }

  return ans;
}
