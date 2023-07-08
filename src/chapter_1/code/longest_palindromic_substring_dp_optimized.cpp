#include <string>
using namespace std;
string longestPalindromeTwoPointer(const string &s) {

  int begin = 0, length = 1;
  int start = s.size() - 1;

  while (start >= 0) {
    for (int i = 0; i < 2 && start + i < s.size(); i++) {
      int localStart = start, localEnd = start + i;
      bool previous = false;
      while (localStart >= 0 && localEnd < s.size()) {
        if (localStart == localEnd) {
          previous = true;
        } else if (localStart + 1 == localEnd && s[localStart] == s[localEnd]) {
          previous = true;
        } else {
          previous = previous && s[localStart] == s[localEnd];
        }

        if (previous && localEnd - localStart + 1 > length) {
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
