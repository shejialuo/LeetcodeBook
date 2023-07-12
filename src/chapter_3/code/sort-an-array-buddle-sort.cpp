#include <vector>
using namespace std;

void buddleSort(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = nums.size() - 1; j > i; j--) {
      if (nums[j] < nums[j - 1]) {
        swap(nums[j], nums[j - 1]);
      }
    }
  }
}
