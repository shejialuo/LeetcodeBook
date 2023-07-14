#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> st{};
  stack<int> qu{};

public:
  MyQueue() {}

  void push(int x) { st.push(x); }

  int pop() {
    int value = peek();
    qu.pop();
    return value;
  }

  int peek() {
    if (!qu.empty()) {
      return qu.top();
    } else {
      while (!st.empty()) {
        qu.push(st.top());
        st.pop();
      }
      return qu.top();
    }
  }

  bool empty() { return st.empty() && qu.empty(); }
};
