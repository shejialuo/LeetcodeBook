#include <algorithm>
#include <utility>
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

pair<int, int> robTreeDP(TreeNode *node) {
  if (node != nullptr) {

    auto [leftWithoutThievery, leftWithThievery] = robTreeDP(node->left);
    auto [rightWithoutThievery, rightWithThievery] = robTreeDP(node->right);

    int nodeWithThievery =
        node->val + leftWithoutThievery + rightWithoutThievery;

    int nodeWithoutThievery = max(leftWithoutThievery, leftWithThievery) +
                              max(rightWithoutThievery, rightWithThievery);

    return {nodeWithoutThievery, nodeWithThievery};
  }
  return {0, 0};
}

int rob(TreeNode *root) {
  auto [val1, val2] = robTreeDP(root);
  return max(val1, val2);
}
