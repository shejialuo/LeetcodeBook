#include <string>
#include <vector>
using namespace std;

vector<string> letter{"abc", "def", "ghi", "jkl",
"mno", "pqrs", "tuv", "wxyz"};

void helper(vector<string> &result, string &str, const string &digits, int i) {
  if (i == str.size()) {
    result.push_back(str);
    return;
  }

  for (char c : letter[digits[i] - '2']) {
    str[i] = c;
    helper(result, str, digits, i + 1);
  }
}

vector<string> letterCombinations(string digits) {

  vector<string> result{};
  if (digits.empty()) {
    return result;
  }
  string str{};
  str.resize(digits.size());
  helper(result, str, digits, 0);
  return result;
}
