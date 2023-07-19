struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val) {
  TreeNode *ptr = root, *parent = nullptr;

  while (ptr != nullptr) {
    parent = ptr;
    if (ptr->val > val) {
      ptr = ptr->left;
    } else {
      ptr = ptr->right;
    }
  }

  TreeNode *node = new TreeNode{val};
  if (parent != nullptr) {
    if (parent->val > val) {
      parent->left = node;
    } else {
      parent->right = node;
    }
  } else {
    return node;
  }
  return root;
}
