#include <algorithm>
#include <vector>
using namespace std;

void subsetsMathWay(vector<vector<int>> &ans, vector<int> &nums, int index) {

  if (index < nums.size()) {

    int currentSize = ans.size();
    for (int i = 0; i < currentSize; i++) {
      ans.push_back(ans[i]);
    }
    for (int i = currentSize; i < ans.size(); i++) {
      ans[i].push_back(nums[index]);
    }

    while (index + 1 < nums.size() && nums[index + 1] == nums[index]) {

      int size = ans.size();

      for (int i = currentSize; i < size; i++) {
        ans.push_back(ans[i]);
      }

      for (int i = size; i < ans.size(); i++) {
        ans[i].push_back(nums[index]);
      }

      currentSize = size;
      index++;
    }
    subsetsMathWay(ans, nums, index + 1);
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans{};

  ans.push_back({});
  subsetsMathWay(ans, nums, 0);
  return ans;
}
