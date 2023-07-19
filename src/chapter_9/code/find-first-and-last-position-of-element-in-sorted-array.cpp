#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int target) {
  int start = 0, end = nums.size();
  while (start < end) {
    int mid = (start + end) / 2;
    if (nums[mid] >= target) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int upperBound(vector<int> &nums, int target) {
  int start = 0, end = nums.size();
  while (start < end) {
    int mid = (start + end) / 2;
    if (nums[mid] <= target) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return start;
}

vector<int> searchRange(vector<int> &nums, int target) {
  int start = lowerBound(nums, target);
  int end = upperBound(nums, target);

  if (start < nums.size() && nums[start] == target)
    return vector<int>{start, end - 1};
  else
    return vector<int>{-1, -1};
}
