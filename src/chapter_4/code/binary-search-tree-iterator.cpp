#include <stack>
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

class BSTIterator {
private:
  stack<TreeNode *> st;

  void pushLeft(TreeNode *node) {
    while (node != nullptr) {
      st.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root) { pushLeft(root); }

  int next() {
    TreeNode *current = st.top();
    st.pop();
    pushLeft(current->right);
    return current->val;
  }

  bool hasNext() { return !st.empty(); }
};
