#include <string>

using namespace std;

string simplifyPath(string path) {
  string ans{};

  for (int i = 0; i < path.size(); i++) {
    // find the next '/', if exist
    // [i, j) would be the next path

    int j = i;
    while (j < path.size() && path[j] != '/') {
      j++;
    }

    string sub = path.substr(i, j - i);

    // There would be situations for multiple '/'
    // or '.' in this situation we should do nothing
    if (sub == "." || sub.empty()) {
      // do nothing
    } else if (sub == "..") {
      // handle the ans, just pop it.
      while (!ans.empty()) {
        if (ans.back() == '/') {
          ans.pop_back();
          break;
        }
        ans.pop_back();
      }
    } else {
      ans += "/" + std::move(sub);
    }
    i = j;
  }

  // handle the special case.
  if (ans.empty()) {
    ans = "/";
  }

  return ans;
}
