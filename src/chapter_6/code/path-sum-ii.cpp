#include <vector>
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

vector<vector<int>> ans{};

void dfs(TreeNode *node, vector<int> &path, int &targetSum, int sum) {
  if (node != nullptr) {
    sum += node->val;
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      if (sum == targetSum) {
        ans.push_back(path);
      }
    }
    dfs(node->left, path, targetSum, sum);
    dfs(node->right, path, targetSum, sum);
    path.pop_back();
  }
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
  vector<int> path{};
  dfs(root, path, targetSum, 0);
  return ans;
}
