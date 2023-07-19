struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void recoverTreeHelper(TreeNode *node, TreeNode *&pre, TreeNode *&p1,
                       TreeNode *&p2) {
  if (node != nullptr) {
    recoverTreeHelper(node->left, pre, p1, p2);
    if (pre != nullptr && pre->val > node->val) {
      if (p1 == nullptr) {
        p1 = pre;
      }
      p2 = node;
    }
    pre = node;
    recoverTreeHelper(node->right, pre, p1, p2);
  }
}

void recoverTree(TreeNode *root) {
  TreeNode *pre = nullptr, *p1 = nullptr, *p2 = nullptr;
  recoverTreeHelper(root, pre, p1, p2);
  swap(p1->val, p2->val);
}
