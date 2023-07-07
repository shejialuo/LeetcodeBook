#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSumTwoPointer(vector<int> &nums) {
  vector<vector<int>> ans{};
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {

    // 去重一 (Example 1.1.1)
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int start = i + 1, end = nums.size() - 1;
    while (start < end) {
      if (nums[i] + nums[start] + nums[end] == 0) {
        ans.push_back({nums[i], nums[start], nums[end]});

        // 去重二 (Example 1.1.2)
        int startPivot = nums[start], endPivot = nums[end];
        while (start < end && nums[start] == startPivot) {
          start++;
        }
        while (start < end && nums[end] == endPivot) {
          end--;
        }

      } else if (nums[i] + nums[start] + nums[end] > 0) {
        end--;
      } else {
        start++;
      }
    }
  }
  return ans;
}
