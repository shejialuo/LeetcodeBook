#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
  int numZero = 0, numOne = 0, numTwo = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      numZero++;
    } else if (nums[i] == 1) {
      numOne++;
    } else {
      numTwo++;
    }
  }

  for (int i = 0; i < numZero; i++) {
    nums[i] = 0;
  }
  for (int i = numZero; i < numZero + numOne; i++) {
    nums[i] = 1;
  }
  for (int i = numZero + numOne; i < numZero + numOne + numTwo; i++) {
    nums[i] = 2;
  }
}
