#include <string>
#include <unordered_map>
using namespace std;

string addTwoNumber(const string &num1, const string &num2) {
  int c = 0;
  int i = num1.size() - 1, j = num2.size() - 1;
  string ans{};
  int length = max(i, j) + 1;
  ans.resize(length + 1);
  while (i >= 0 || j >= 0) {

    int val1 = i >= 0 ? num1[i] - '0' : 0;
    int val2 = j >= 0 ? num2[j] - '0' : 0;

    int sum = val1 + val2 + c;
    ans[length--] = (sum % 10 + '0');
    c = sum / 10;
    i--;
    j--;
  }

  if (c != 0) {
    ans[length] = c + '0';
  } else {
    ans.erase(0, 1);
  }
  return ans;
}

string multiply(string num1, string num2) {
  unordered_map<int, string> table{};
  if (num1 == "0" || num2 == "0") {
    return "0";
  }

  string ans{};

  int numOfZero = 0;

  for (int i = num2.size() - 1; i >= 0; i--) {

    int current = num2[i] - '0';

    string mul{};

    if (table.count(current)) {
      mul = table[current];
    } else {
      int C = 0;
      mul.resize(num1.size() + 1, '0');
      int index = num1.size();

      for (int j = num1.size() - 1; j >= 0; j--) {
        int n = (current * (num1[j] - '0') + C) % 10;
        C = (current * (num1[j] - '0') + C) / 10;
        mul[index--] = n + '0';
      }

      if (C != 0) {
        mul[index] = C + '0';
      } else {
        mul.erase(0, 1);
      }

      table[current] = mul;
    }

    mul.insert(mul.end(), numOfZero, '0');
    numOfZero++;

    ans = addTwoNumber(ans, mul);
  }

  return ans;
}
