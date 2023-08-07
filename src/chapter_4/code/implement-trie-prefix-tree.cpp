#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
private:
  class Node {
  private:
    char key;   // the value stored
    bool isEnd; // If it is an end node

    unordered_map<char, unique_ptr<Node>> children;

  public:
    Node() = default;
    Node(char k, bool end) : key{k}, isEnd{end} {}

    void setEnd(bool end) { isEnd = end; }
    bool getEnd() { return isEnd; }

    unique_ptr<Node> *newChildren(char c) {
      auto ptr = make_unique<Node>(c, false);
      children.insert({c, std::move(ptr)});
      return &children[c];
    }

    unique_ptr<Node> *nextChildren(char c) {
      if (children.count(c)) {
        return &children[c];
      }
      return nullptr;
    }
  };

  unique_ptr<Node> root;

public:
  Trie() { root = std::make_unique<Node>('+', false); }

  void insert(string word) {
    unique_ptr<Node> *ptr = &root;
    for (char c : word) {
      unique_ptr<Node> *child = (*ptr)->nextChildren(c);
      if (child == nullptr) {
        ptr = (*ptr)->newChildren(c);
      } else {
        ptr = child;
      }
    }
    (*ptr)->setEnd(true);
  }

  bool search(string word) {
    unique_ptr<Node> *ptr = &root;
    for (auto c : word) {
      ptr = (*ptr)->nextChildren(c);
      if (ptr == nullptr) {
        return false;
      }
    }
    return (*ptr)->getEnd();
  }

  bool startsWith(string prefix) {
    unique_ptr<Node> *ptr = &root;
    for (auto c : prefix) {
      ptr = (*ptr)->nextChildren(c);
      if (ptr == nullptr) {
        return false;
      }
    }
    return true;
  }
};
