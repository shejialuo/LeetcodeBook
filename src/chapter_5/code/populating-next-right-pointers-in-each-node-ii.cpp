#include <memory>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
  Node *ptr = root;
  auto dummy = make_unique<Node>();
  while (ptr != nullptr) {

    Node *pre = dummy.get();
    pre->next = nullptr;

    Node *level = ptr;
    while (level != nullptr) {
      if (level->left != nullptr) {
        pre->next = level->left;
        pre = level->left;
      }
      if (level->right != nullptr) {

        pre->next = level->right;
        pre = level->right;
      }
      level = level->next;
    }
    ptr = dummy->next;
  }
  return root;
}
