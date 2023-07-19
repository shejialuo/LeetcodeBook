#include <unordered_map>
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

  unordered_map<long, int> prefix{};
  int pathSumHelper(TreeNode *node, long sum, int targetSum) {
    if (node != nullptr) {
      int ans = 0;
      sum += node->val;
      ans += prefix[sum - targetSum];

      prefix[sum]++;
      ans += pathSumHelper(node->left, sum, targetSum);
      ans += pathSumHelper(node->right, sum, targetSum);
      prefix[sum]--;
      sum -= node->val;
      return ans;
    }
    return 0;
  }

  int pathSum(TreeNode *root, int targetSum) {
    prefix[0] = 1;
    return pathSumHelper(root, 0, targetSum);
  }