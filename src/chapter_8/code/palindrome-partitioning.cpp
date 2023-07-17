#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string &str) {
  for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

void partitionHelper(int startIndex, string &s, vector<string> &one,
                     vector<vector<string>> &ans) {
  if (startIndex == s.size()) {
    ans.push_back(one);
    return;
  }

  for (int i = startIndex; i < s.size(); i++) {
    string sub = s.substr(startIndex, i - startIndex + 1);
    if (isPalindrome(sub)) {
      one.push_back(sub);
      partitionHelper(i + 1, s, one, ans);
      one.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans{};
  vector<string> one{};
  partitionHelper(0, s, one, ans);
  return ans;
}
