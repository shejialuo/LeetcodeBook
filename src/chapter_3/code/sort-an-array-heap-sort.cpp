#include <vector>
using namespace std;

class Heap {
private:
  vector<int> data;
  size_t heapSize;

  int left(int index) { return 2 * index; }
  int right(int index) { return 2 * index + 1; }

public:
  Heap() = delete;
  Heap(const vector<int> &d) : data{d}, heapSize{data.size()} { buildHeap(); }

  void maxHeapify(int index) {
    int largest = index;
    if (left(index) < heapSize && data[left(index)] > data[largest]) {
      largest = left(index);
    }
    if (right(index) < heapSize && data[right(index)] > data[largest]) {
      largest = right(index);
    }

    if (largest != index) {
      swap(data[largest], data[index]);
      maxHeapify(largest);
    }
  }

  void buildHeap() {
    for (int i = data.size() / 2; i >= 0; i--) {
      maxHeapify(i);
    }
  }

  void sortedArray() {
    while (heapSize > 0) {
      swap(data[heapSize - 1], data[0]);
      heapSize--;
      maxHeapify(0);
    }
  }
};
