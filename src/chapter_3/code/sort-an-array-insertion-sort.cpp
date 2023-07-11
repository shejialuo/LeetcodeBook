#include <vector>
using namespace std;

void insertionSort(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    int j = i - 1;
    int value = nums[i];
    while (j >= 0 && value < nums[j]) {
      nums[j + 1] = nums[j];
      j--;
    }

    nums[j + 1] = value;
  }
}