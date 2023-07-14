#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
  unordered_map<char, char> table{{'(', ')'}, {'[', ']'}, {'{', '}'}};
  stack<char> st;
  for (const char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else {
      if (st.empty() || c != table[st.top()]) {
        return false;
      } else {
        st.pop();
      }
    }
  }
  return st.empty();
}
