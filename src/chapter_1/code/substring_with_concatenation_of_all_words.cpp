#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start

vector<int> findSubstring(string s, vector<string> &words) {
  int stringLength = words[0].size();
  int wholeWindowSize = words.size() * stringLength;

  vector<int> ans{};

  for (int i = 0; i < stringLength && i + wholeWindowSize <= s.size(); ++i) {
    unordered_map<string, int> window{};

    for (int j = i; j < wholeWindowSize + i; j += stringLength) {
      window[s.substr(j, stringLength)]++;
    }

    for (auto &&word : words) {
      if (--window[word] == 0) {
        window.erase(word);
      }
    }

    for (int windowStart = i; windowStart + wholeWindowSize <= s.size();
         windowStart += stringLength) {
      if (windowStart != i) {

        string sub = s.substr(windowStart + wholeWindowSize - stringLength,
                              stringLength);
        if (++window[sub] == 0) {
          window.erase(sub);
        }

        sub = s.substr(windowStart - stringLength, stringLength);
        if (--window[sub] == 0) {
          window.erase(sub);
        }
      }

      if (window.empty()) {
        ans.push_back(windowStart);
      }
    }
  }
  return ans;
}
