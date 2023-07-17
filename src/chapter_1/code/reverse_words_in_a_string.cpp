#include <string>
using namespace std;

void trimString(string &s) {
  int index = 0, current = 0;
  while (index < s.size()) {
    if (s[index] != ' ') {
      while (index < s.size() && s[index] != ' ') {
        s[current++] = s[index++];
      }
      s[current++] = ' ';
    }
    index++;
  }

  s.erase(current - 1, s.size() - current + 1);
}

void reverseString(string &s, int start, int end) {
  while (start < end) {
    swap(s[start++], s[end--]);
  }
}

string reverseWords(string s) {
  trimString(s);
  reverseString(s, 0, s.size() - 1);

  int wordStart = 0, wordEnd = 0;
  while (wordEnd < s.size()) {
    while (wordEnd < s.size() && s[wordEnd] != ' ') {
      wordEnd++;
    }
    reverseString(s, wordStart, wordEnd - 1);
    wordEnd++;
    wordStart = wordEnd;
  }

  return s;
}
