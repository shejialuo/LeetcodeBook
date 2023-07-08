#include <string>
#include <vector>
using namespace std;

string longestPalindromeDP(const string &s) {
  vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

  int begin = 0, length = 1;

  int start = s.size() - 1;

  while (start >= 0) {
    for (int i = 0; i < 2 && start + i < s.size(); i++) {
      int localStart = start, localEnd = start + i;
      while (localStart >= 0 && localEnd < s.size()) {
        if (localStart == localEnd) {
          dp[localStart][localEnd] = true;
        } else if (localStart + 1 == localEnd && s[localStart] == s[localEnd]) {
          dp[localStart][localEnd] = true;
        } else {
          dp[localStart][localEnd] =
              dp[localStart + 1][localEnd - 1] && s[localStart] == s[localEnd];
        }

        if (dp[localStart][localEnd] && localEnd - localStart + 1 > length) {
          begin = localStart;
          length = localEnd - localStart + 1;
        }
        localStart--;
        localEnd++;
      }
    }
    start--;
  }
  return s.substr(begin, length);
}
