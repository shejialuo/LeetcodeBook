struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val) {
  TreeNode *ptr = root;
  while (ptr != nullptr) {
    if (ptr->val == val) {
      return ptr;
      break;
    } else if (ptr->val > val) {
      ptr = ptr->left;
    } else {
      ptr = ptr->right;
    }
  }
  return ptr;
}
