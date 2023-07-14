#include <string>
#include <vector>
using namespace std;

void helper(string &s, vector<string> &ans, int i, int leftBracket,
            int rightBracket) {

  if (i == s.size()) {
    ans.push_back(s);
    return;
  }

  if (leftBracket < s.size() / 2) {
    s[i] = '(';
    helper(s, ans, i + 1, leftBracket + 1, rightBracket);
  }

  if (rightBracket < leftBracket) {
    s[i] = ')';
    helper(s, ans, i + 1, leftBracket, rightBracket + 1);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> ans{};
  string s{};
  s.resize(2 * n);
  helper(s, ans, 0, 0, 0);
  return ans;
}
