#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans{};
  queue<TreeNode *> qu{};
  if (root != nullptr) {
    qu.push(root);
  }
  while (!qu.empty()) {
    int size = qu.size();
    vector<int> levelNode{};
    for (int i = 0; i < size; ++i) {
      TreeNode *node = qu.front();
      qu.pop();
      levelNode.push_back(node->val);
      if (node->left != nullptr) {
        qu.push(node->left);
      }
      if (node->right != nullptr) {
        qu.push(node->right);
      }
    }
    ans.push_back(std::move(levelNode));
  }
  return ans;
}
