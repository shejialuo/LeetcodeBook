#include <vector>
using namespace std;

class MyCircularQueue {
private:
  vector<int> data{};
  int rear = 0, front = 0, count = 0;

public:
  MyCircularQueue(int k) { data.resize(k); }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    data[rear] = value;
    rear = (rear + 1) % data.size();
    count++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    front = (front + 1) % data.size();
    count--;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return data[front];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    if (rear - 1 < 0) {
      return data[rear - 1 + data.size()];
    }
    return data[rear - 1];
  }

  bool isEmpty() { return rear == front; }

  bool isFull() { return (rear + 1) % data.size() == front; }
};
