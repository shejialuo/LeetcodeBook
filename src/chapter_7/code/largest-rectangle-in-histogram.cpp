

#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
  stack<int> st{};

  heights.insert(heights.begin(), 0);
  heights.push_back(0);

  int largest = 0;
  for (int i = 0; i < heights.size(); i++) {

    while (!st.empty() && heights[i] < heights[st.top()]) {
      int current = st.top();
      st.pop();
      if (!st.empty()) {
        int height = heights[current];
        int width = i - st.top() - 1;
        largest = max(largest, height * width);
      }
    }

    st.push(i);
  }
  return largest;
}
