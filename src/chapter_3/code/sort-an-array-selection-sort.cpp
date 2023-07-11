#include <vector>
#include <limits>
using namespace std;

void selectionSort(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    int minValue = numeric_limits<int>::max();
    int k = -1;

    for (int j = i; j < nums.size(); j++) {
      if (nums[j] < minValue) {
        k = j;
        minValue = nums[j];
      }
    }

    swap(nums[i], nums[k]);
  }
}
