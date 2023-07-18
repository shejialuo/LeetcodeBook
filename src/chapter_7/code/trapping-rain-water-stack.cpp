#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int trapMonolithicStack(vector<int> &height) {
  stack<int> st{};

  int totalWater = 0;
  for (int i = 0; i < height.size(); i++) {

    while (!st.empty() && height[i] > height[st.top()]) {
      int mid = st.top();
      st.pop();
      if (!st.empty()) {
        int h = min(height[i], height[st.top()]) - height[mid];
        int w = i - st.top() - 1;
        totalWater += h * w;
      }
    }
    st.push(i);
  }
  return totalWater;
}

int trap(vector<int> &height) { return trapMonolithicStack(height); }
