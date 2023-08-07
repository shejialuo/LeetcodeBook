#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> ans{};

  int index = 0;
  bool isOverlap = false;

  while (index < intervals.size()) {
    if (newInterval[0] > intervals[index][1]) {
      ans.push_back(intervals[index++]);
    } else {
      isOverlap = true;

      vector<int> interval(2, 0);
      interval[0] = min(newInterval[0], intervals[index][0]);

      while (index < intervals.size() &&
             newInterval[1] >= intervals[index][0]) {
        index++;
      }

      if (index == 0) {
        interval[1] = newInterval[1];
      } else {
        interval[1] = max(intervals[index - 1][1], newInterval[1]);
      }

      ans.push_back(std::move(interval));
      break;
    }
  }

  if (!isOverlap) {
    ans.push_back(newInterval);
  } else {
    while (index < intervals.size()) {
      ans.push_back(intervals[index++]);
    }
  }

  return ans;
}
