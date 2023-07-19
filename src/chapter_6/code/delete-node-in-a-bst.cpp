#include <memory>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void helper(TreeNode *parent, TreeNode *ptr, TreeNode *val) {
  if (parent->left == ptr) {
    parent->left = val;
  } else {
    parent->right = val;
  }
}
TreeNode *deleteNode(TreeNode *root, int key) {
  TreeNode *ptr = root;

  auto aux = make_unique<TreeNode>(-1);
  aux->left = root;
  TreeNode *parent = aux.get();

  // search the corresponding node
  while (ptr != nullptr) {
    if (ptr->val == key) {
      break;
    } else {
      parent = ptr;
      if (ptr->val > key) {
        ptr = ptr->left;
      } else {
        ptr = ptr->right;
      }
    }
  }

  if (ptr != nullptr) {
    // When there is no children for the ptr, we just delete the node
    if (ptr->left == nullptr && ptr->right == nullptr) {
      helper(parent, ptr, nullptr);
    } else if (ptr->left == nullptr) {
      // When the ptr->left is nullptr
      helper(parent, ptr, ptr->right);
    } else if (ptr->right == nullptr) {
      // When the ptr->right is nullptr
      helper(parent, ptr, ptr->left);
    } else {

      // We need to find the successor here.
      TreeNode *rightNode = ptr->right;

      TreeNode *minNode = rightNode;
      TreeNode *minNodeParent = nullptr;

      while (minNode->left != nullptr) {
        minNodeParent = minNode;
        minNode = minNode->left;
      }

      helper(parent, ptr, minNode);

      if (minNodeParent != nullptr) {
        minNodeParent->left = minNode->right;
        minNode->right = rightNode;
        minNode->left = ptr->left;
      } else {
        minNode->left = ptr->left;
      }
    }
  }

  return aux->left;
}
