#include <algorithm>
#include <vector>
using namespace std;

void permuteUniqueHelper(vector<int> &nums, vector<bool> &visited,
                         vector<int> &one, vector<vector<int>> &ans) {

  if (one.size() == nums.size()) {
    ans.push_back(one);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {

    // Only the one level , so the !visited[i - 1] is a must.
    if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
      continue;
    }

    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    one.push_back(nums[i]);
    permuteUniqueHelper(nums, visited, one, ans);
    one.pop_back();
    visited[i] = false;
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
  vector<vector<int>> ans{};
  vector<int> one{};
  sort(nums.begin(), nums.end());
  vector<bool> visited(nums.size(), false);
  permuteUniqueHelper(nums, visited, one, ans);
  return ans;
}
