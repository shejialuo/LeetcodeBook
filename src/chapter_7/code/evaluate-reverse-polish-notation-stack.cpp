#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  static int add(int val1, int val2) { return val1 + val2; }
  static int minus(int val1, int val2) { return val1 - val2; }
  static int multiply(int val1, int val2) { return val1 * val2; }
  static int div(int val1, int val2) { return val1 / val2; }

  unordered_map<string, function<int(int, int)>> fns{
      {"+", add},
      {"-", minus},
      {"*", multiply},
      {"/", div},
  };

  int evalRPNStack(vector<string> &tokens) {
    stack<int> st{};

    for (auto &&token : tokens) {
      if (fns.count(token) == 0) {
        st.push(stoi(token));
      } else {
        int val1 = st.top();
        st.pop();
        int val2 = st.top();
        st.pop();
        st.push(fns[token](val2, val1));
      }
    }

    return st.top();
  }

public:
  int evalRPN(vector<string> &tokens) {
    return evalRPNStack(tokens);
  }
};
