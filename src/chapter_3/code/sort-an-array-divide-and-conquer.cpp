#include <limits>
#include <vector>
using namespace std;

void mergeArray(vector<int> &nums, int start, int mid, int end) {
  vector<int> array1(mid - start + 2, 0);
  for (int i = 0; i < mid - start + 1; i++) {
    array1[i] = nums[i + start];
  }
  array1.back() = numeric_limits<int>::max();

  vector<int> array2(end - mid + 1, 0);
  for (int i = 0; i < end - mid; i++) {
    array2[i] = nums[i + mid + 1];
  }
  array2.back() = numeric_limits<int>::max();

  for (int i = 0, j = 0, k = start; k <= end; k++) {
    if (array1[i] < array2[j]) {
      nums[k] = array1[i++];
    } else {
      nums[k] = array2[j++];
    }
  }
}

void sortArrayDivideAndConquer(vector<int> &nums, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    sortArrayDivideAndConquer(nums, start, mid);
    sortArrayDivideAndConquer(nums, mid + 1, end);
    mergeArray(nums, start, mid, end);
  }
}
