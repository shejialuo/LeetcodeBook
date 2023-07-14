#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int longestLength = 0;

  unordered_map<char, int> visitedElement{};

  int windowStart = 0, windowEnd = 0;
  while (windowEnd < s.size()) {
    if (!visitedElement[s[windowEnd]]) {
      visitedElement[s[windowEnd++]] = windowEnd + 1;
    } else {
      longestLength = max(windowEnd - windowStart, longestLength);
      while (windowStart < visitedElement[s[windowEnd]]) {
        visitedElement[s[windowStart++]] = 0;
      }
    }
  }

  longestLength = max(windowEnd - windowStart, longestLength);

  return longestLength;
}
