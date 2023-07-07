#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  int start = 0, end = nums.size() - 1;
  while (start < end) {
    int sum = nums[start] + nums[end];
    if (sum < target) {
      start++;
    } else if (sum > target) {
      end--;
    } else {
      return {start, end};
    }
  }
  return {};
}
