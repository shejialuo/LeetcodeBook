#include <array>
#include <string>
using namespace std;

class BrowserHistory {
private:
  array<string, 1000> histories{};
  int ptr{0};
  int length{0};

public:
  BrowserHistory(string homepage) {
    histories[ptr++] = homepage;
    length = ptr;
  }

  void visit(string url) {
    histories[ptr++] = url;
    length = ptr;
  }

  string back(int steps) {
    ptr = ptr - steps >= 1 ? ptr - steps : 1;
    return histories[ptr - 1];
  }

  string forward(int steps) {
    ptr = ptr + steps <= length ? ptr + steps : length;
    return histories[ptr - 1];
  }
};
