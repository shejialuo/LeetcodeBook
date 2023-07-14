#include <queue>
using namespace std;

class MyStack {
private:
  queue<int> qu{};

public:
  MyStack() {}

  void push(int x) {
    qu.push(x);
    for (int i = 1; i < qu.size(); ++i) {
      qu.push(qu.front());
      qu.pop();
    }
  }

  int pop() {
    int value = top();
    qu.pop();
    return value;
  }

  int top() { return qu.front(); }

  bool empty() { return qu.empty(); }
};
