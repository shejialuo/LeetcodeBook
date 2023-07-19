#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  int start = 0, end = nums.size();
  while (start < end) {
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      // There are two situations whe nums[mid] > target,
      // if the target is less than nums[0], and we
      // are in the first array, which means, nums[mid]
      // is greater or equal to nums[0].
      if (target < nums[0] && nums[mid] >= nums[0]) {
        start = mid + 1;
      } else {
        end = mid;
      }
    } else {
      // There are two situations when nums[mid] < target.
      // if the target is greater than or equal to nums[0],
      // and we are in the second array, which means
      // nums[mid] < nums[0].
      if (target >= nums[0] && nums[mid] < nums[0]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
  }
  return -1;
}
