#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void findAllShortestLadders(
    vector<vector<string>> &ans, vector<string> &one, const string &current,
    unordered_map<string, unordered_set<string>> &parents) {
  if (parents[current].empty()) {
    ans.push_back(vector<string>{one.rbegin(), one.rend()});
    return;
  }

  for (auto &&parent : parents[current]) {
    one.push_back(parent);
    findAllShortestLadders(ans, one, parent, parents);
    one.pop_back();
  }
}

vector<vector<string>> findLadders(string beginWord, string endWord,
                                   vector<string> &wordList) {

  unordered_set<string> notVisited{wordList.cbegin(), wordList.cend()};
  vector<string> one{};

  vector<vector<string>> ans{};
  unordered_map<string, unordered_set<string>> parents{};

  bool found{false};
  queue<string> qu{};
  qu.push(beginWord);
  notVisited.erase(beginWord);

  while (!qu.empty() && !found) {
    int size = qu.size();
    unordered_set<string> level{};
    for (int i = 0; i < size; i++) {
      string &current = qu.front();
      string next = current;

      for (int index = 0; index < next.size(); index++) {
        const char original = next[index];

        for (char c = 'a'; c <= 'z'; c++) {
          if (c != original) {
            next[index] = c;
            if (notVisited.count(next)) {
              if (next == endWord) {
                found = true;
                parents[next].insert(current);
              } else {
                parents[next].insert(current);
                level.insert(next);
              }
            }
          }
          next[index] = original;
        }
      }

      qu.pop();
    }
    for (auto &&l : level) {
      notVisited.erase(l);
      qu.push(l);
    }
  }

  if (found) {
    one.push_back(endWord);
    findAllShortestLadders(ans, one, endWord, parents);
  }

  return ans;
}
