#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int openLock(vector<string> &deadends, string target) {
  unordered_set<string> visited{deadends.cbegin(), deadends.cend()};

  const string start = "0000";
  if (start == target) {
    return 0;
  }

  queue<string> qu{};
  if (!visited.count(start)) {
    qu.push(start);
    visited.insert(start);
  }

  int ans = 1;
  while (!qu.empty()) {
    int length = qu.size();

    for (int i = 0; i < length; i++) {
      string password = qu.front();
      for (int index = 0; index < password.size(); index++) {
        char original = password[index];
        for (int j = 0, plus = 9; j < 2; j++, plus += 3) {
          password[index] = (password[index] - '0' + plus) % 10 + '0';
          if (password == target) {
            return ans;
          }
          if (!visited.count(password)) {
            visited.insert(password);
            qu.push(password);
          }
        }
        password[index] = original;
      }
      qu.pop();
    }
    ans++;
  }
  return -1;
}
