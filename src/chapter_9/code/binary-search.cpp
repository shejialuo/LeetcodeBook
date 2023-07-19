#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  int start = 0, end = nums.size();
  while (start < end) {
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}
