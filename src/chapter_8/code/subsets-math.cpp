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
    subsetsMathWay(ans, nums, index + 1);
  }
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ans{};

  ans.push_back(vector<int>{});
  subsetsMathWay(ans, nums, 0);
  return ans;
}
