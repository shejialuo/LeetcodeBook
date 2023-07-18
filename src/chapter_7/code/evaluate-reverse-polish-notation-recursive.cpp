#include <functional>
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

  int evalRPNHelper(vector<string> &tokens, int &current) {
    int value = 0;

    if (current >= 0) {
      const string &token = tokens[current--];
      if (fns.count(token) == 0) {
        return stoi(token);
      } else {
        int val2 = evalRPNHelper(tokens, current);
        int val1 = evalRPNHelper(tokens, current);
        value += fns[token](val1, val2);
      }
    }
    return value;
  }

public:
  int evalRPN(vector<string> &tokens) {
    int end = tokens.size() - 1;
    return evalRPNHelper(tokens, end);
  }
};
