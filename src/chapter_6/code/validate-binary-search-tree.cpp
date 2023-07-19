struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool isValidBSTHelper(TreeNode *&pre, TreeNode *node) {
  if (node != nullptr) {
    bool okLeft = isValidBSTHelper(pre, node->left);
    if (pre != nullptr && pre->val >= node->val) {
      return false;
    }
    pre = node;
    return okLeft && isValidBSTHelper(pre, node->right);
  }
  return true;
}

bool isValidBST(TreeNode *root) {
  TreeNode *pre = nullptr;
  return isValidBSTHelper(pre, root);
}
