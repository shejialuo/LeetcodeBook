#include <limits>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> hash{};
  unordered_map<char, int> window{};
  for (char c : t) {
    hash[c]++;
  }
  int windowStart = 0, windowEnd = 0, num = 0;
  int ansStartIndex = 0, ansEndIndex = 0;
  int minLength = numeric_limits<int>::max();
  while (windowEnd < s.size()) {

    if (hash.find(s[windowEnd]) != hash.cend()) {
      window[s[windowEnd]]++;
      if (window[s[windowEnd]] <= hash[s[windowEnd]]) {
        num++;
      }
    }
    windowEnd++;

    while (num == t.size()) {
      while (window[s[windowStart]] == 0) {
        windowStart++;
      }
      if (window[s[windowStart]] <= hash[s[windowStart]]) {
        num--;
      }
      window[s[windowStart]]--;
      if (windowEnd - windowStart < minLength) {
        minLength = windowEnd - windowStart;
        ansStartIndex = windowStart;
        ansEndIndex = windowEnd;
      }
      windowStart++;
    }
  }
  return s.substr(ansStartIndex, ansEndIndex - ansStartIndex);
}
