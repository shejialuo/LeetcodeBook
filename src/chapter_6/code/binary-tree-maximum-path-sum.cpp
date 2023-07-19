#include <algorithm>
#include <limits>
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

int maxPathSumHelper(TreeNode *node, int &maxSum) {
  if (node != nullptr) {
    int left = maxPathSumHelper(node->left, maxSum);
    int right = maxPathSumHelper(node->right, maxSum);

    int maxPathValue = max({left + node->val, right + node->val, node->val});
    maxSum = max({maxSum, left + right + node->val, maxPathValue});

    return maxPathValue;
  }
  return 0;
}

int maxPathSum(TreeNode *root) {
  int maxSum = numeric_limits<int>::min();
  maxPathSumHelper(root, maxSum);
  return maxSum;
}
