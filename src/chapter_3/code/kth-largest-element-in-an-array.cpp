#include <vector>
using namespace std;

int partition(vector<int> &nums, int start, int end) {
  int pivot = nums[end];
  int i = start - 1;
  for (int j = start; j < end; ++j) {
    if (nums[j] > pivot) {
      i++;
      if (i != j)
        swap(nums[i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[end]);
  return i + 1;
}

int findKthLargestHelper(vector<int> &nums, int start, int end, int k) {
  if (start == end) {
    return nums[start];
  }

  int mid = partition(nums, start, end);
  int position = mid - start + 1;
  if (position == k) {
    return nums[mid];
  } else if (k < position) {
    return findKthLargestHelper(nums, start, mid - 1, k);
  } else {
    return findKthLargestHelper(nums, mid + 1, end, k - position);
  }
}

int findKthLargest(vector<int> &nums, int k) {
  return findKthLargestHelper(nums, 0, nums.size() - 1, k);
}
