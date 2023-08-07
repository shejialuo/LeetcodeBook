#include <string>
#include <vector>
using namespace std;

int numDecodings(string s) {
  vector<int> dp(s.size() + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < s.size(); i++) {
    int num = 0, time = 1;
    for (int j = i; j > i - 2 && j >= 0; j--, time *= 10) {
      if (s[j] == '0') {
        continue;
      }

      num += (s[j] - '0') * time;
      if (1 <= num && num <= 26) {
        dp[i + 1] += dp[j];
      }
    }
  }

  return dp.back();
}
