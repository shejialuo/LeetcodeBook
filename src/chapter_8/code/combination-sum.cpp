#include <vector>
using namespace std;

vector<vector<int>> ans{};
vector<int> combination{};

void combinationSumHelper(vector<int> &candidates, int index, int sum,
                          int target) {

  if (sum == target) {
    ans.push_back(combination);
  }

  for (int i = index; sum < candidates.size(); i++) {
    if (sum + candidates[i] <= target) {
      combination.push_back(candidates[i]);
      combinationSumHelper(candidates, i, sum + candidates[i], target);
      combination.pop_back();
    }
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  combinationSumHelper(candidates, 0, 0, target);
  return ans;
}
