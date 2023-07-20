#include <iostream>
#include <iterator>
#include <list>
using namespace std;


class FrontMiddleBackQueue {
private:
  list<int> data{};
  list<int>::iterator middle{};

public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    data.push_front(val);

    if (data.size() == 1) {
      // When the length is 1, middle always points to `data.begin()`.
      middle = data.begin();
    } else if (data.size() % 2 == 0) {
      advance(middle, -1);
    }
  }

  void pushMiddle(int val) {
    if (data.empty()) {
      data.push_front(val);
      middle = data.begin();
    } else if (data.size() % 2 == 0) {
      middle = data.insert(next(middle), val);
    } else {
      middle = data.insert(middle, val);
    }
  }

  void pushBack(int val) {
    data.push_back(val);
    if (data.size() == 1) {
      middle = data.begin();
    } else if (data.size() % 2 != 0) {
      advance(middle, 1);
    }
  }

  int popFront() {
    if (data.empty()) {
      return -1;
    }
    int val = data.front();
    data.pop_front();

    if (data.size() == 1) {
      middle = data.begin();
    } else if (!data.empty() && data.size() % 2 != 0) {
      advance(middle, 1);
    }
    return val;
  }

  int popMiddle() {
    if (data.empty()) {
      return -1;
    }

    int val = *middle;
    middle = data.erase(middle);
    if (!data.empty() && data.size() % 2 == 0) {
      advance(middle, -1);
    }
    return val;
  }

  int popBack() {
    if (data.empty()) {
      return -1;
    }

    int val = data.back();
    data.pop_back();

    if (!data.empty() && data.size() % 2 == 0) {
      advance(middle, -1);
    }
    return val;
  }
};
