#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
  int size;
  list<pair<int, int>> items{};
  unordered_map<int, typename list<pair<int, int>>::iterator> keyToIterators{};

public:
  LRUCache(int capacity) : size(capacity) {}

  int get(int key) {
    auto pos = keyToIterators.find(key);
    if (pos == keyToIterators.end()) {
      return -1;
    }

    int value = pos->second->second;
    items.splice(items.begin(), items, pos->second);
    keyToIterators[key] = items.begin();

    return value;
  }

  void put(int key, int value) {
    auto pos = keyToIterators.find(key);
    if (pos == keyToIterators.end()) {
      items.push_front(make_pair(key, value));
      keyToIterators[key] = items.begin();
      if (items.size() > size) {
        keyToIterators.erase(items.back().first);
        items.pop_back();
      }
    } else {
      items.splice(items.begin(), items, pos->second);
      items.front().second = value;
      keyToIterators[key] = items.begin();
    }
  }
};
