#include <algorithm>
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

int minDepth(TreeNode *root) {
  if (root != nullptr) {
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    return 1 + (L && R ? min(L, R) : max(L, R));
  }
  return 0;
}
