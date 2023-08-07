#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> ans{};
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &interval1, const vector<int> &interval2) {
         return interval1[0] < interval2[0];
       });
  for (vector<int> &interval : intervals) {
    if (ans.empty()) {
      ans.push_back(interval);
    } else {
      vector<int> &current = ans.back();
      if (interval[0] > current[1]) {
        ans.push_back(interval);
      } else if (interval[1] <= current[1]) {
        continue;
      } else {
        current[1] = interval[1];
      }
    }
  }

  return ans;
}
