#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool isOneCharacterDiff(const string &word1, const string &word2) {
  int diff = 0;
  for (int i = 0; i < word1.size(); i++) {
    if (word1[i] != word2[i]) {
      if (++diff > 1) {
        return false;
      }
    }
  }
  return true;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
  unordered_set<string> notVisited{wordList.cbegin(), wordList.cend()};
  notVisited.erase(beginWord);

  queue<string> qu{};
  qu.push(beginWord);

  int ans = 1;
  while (!qu.empty()) {

    int length = qu.size();
    for (int i = 0; i < length; i++) {
      const string &word = qu.front();
      if (word == endWord) {
        return ans;
      }

      auto iter = notVisited.begin();
      while (iter != notVisited.end()) {
        if (isOneCharacterDiff(word, *iter)) {
          qu.push(*iter);
          iter = notVisited.erase(iter);
        } else {
          iter++;
        }
      }
      qu.pop();
    }
    ans++;
  }

  return 0;
}
