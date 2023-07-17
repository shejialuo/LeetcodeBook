#include <string>
#include <vector>
using namespace std;

void restoreIpAddressesHelper(int start, int field, string &s,
                              vector<string> &one, vector<string> &ans) {

  if (field == 4 && start == s.size()) {
    string ip{};
    for (int i = 0; i < one.size() - 1; i++) {
      ip += one[i] + ".";
    }
    ip += one.back();
    ans.push_back(std::move(ip));

    return;
  }

  int loopLength = s[start] == '0' ? 1 : 3;

  for (int i = 0; i < loopLength && start + i < s.size(); i++) {
    string sub = s.substr(start, i + 1);
    if (stoi(sub) <= 255) {
      one.push_back(sub);
      restoreIpAddressesHelper(start + i + 1, field + 1, s, one, ans);
      one.pop_back();
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  vector<string> ans{};
  vector<string> one{};
  restoreIpAddressesHelper(0, 0, s, one, ans);
  return ans;
}
