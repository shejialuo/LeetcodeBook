

#include <vector>
using namespace std;

void subsetsHelper(int start, vector<int> &nums, vector<int> &path,
                   vector<vector<int>> &ans) {

  ans.push_back(path);

  for (int i = start; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    subsetsHelper(i + 1, nums, path, ans);
    path.pop_back();
  }
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ans{};

  vector<int> path{};
  subsetsHelper(0, nums, path, ans);
  return ans;
}
