#include <vector>
using namespace std;

int partition(vector<int> &nums, int start, int end) {
  int pivot = nums[end];
  int i = start - 1;
  for (int j = start; j < end; j++) {
    if (nums[j] < pivot) {
      swap(nums[++i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[end]);
  return i + 1;
}

void quickSort(vector<int> &nums, int start, int end) {
  if (start < end) {
    int mid = partition(nums, start, end);
    quickSort(nums, start, mid - 1);
    quickSort(nums, mid + 1, end);
  }
}
