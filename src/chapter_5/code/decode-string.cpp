#include <cassert>
#include <cctype>
#include <string>
using namespace std;

string decodeStringHelper(const string &s, size_t &index) {
  string decode{};
  size_t accumulate = 0;
  while (index < s.size()) {
    char c = s[index];
    index++;
    if (c == '[') {
      // solve the subproblem
      string result = decodeStringHelper(s, index);
      for (int j = 0; j < accumulate; ++j) {
        decode.append(result);
      }
      // reset `accumulate` to be zero.
      accumulate = 0;
    } else if (c == ']') {
      return decode;
    } else if (isdigit(c)) {
      accumulate = (c - '0') + (accumulate * 10);
    } else {
      decode.push_back(c);
    }
  }
  return decode;
}

string decodeString(string s) {
  size_t start = 0;
  return decodeStringHelper(s, start);
}
