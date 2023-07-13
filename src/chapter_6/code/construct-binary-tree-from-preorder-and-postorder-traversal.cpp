#include <unordered_map>
#include <unordered_set>
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

void constructFromPrePostHelper(TreeNode *node, vector<int> &preorder,
  vector<int> &postorder,
  unordered_map<int, int> &valueToIndexPre,
  unordered_map<int, int> &valueToIndexPost,
  unordered_set<int> visited) {

  if (node == nullptr) {
    return;
  }

  int preorderIndex = valueToIndexPre[node->val];

  if (preorderIndex + 1 < preorder.size()) {
    int left = preorder[preorderIndex + 1];
    if (!visited.count(left)) {
      visited.insert(left);
      node->left = new TreeNode{left};
    }
  }

  int postorderIndex = valueToIndexPost[node->val];
  if (postorderIndex - 1 >= 0) {
    int right = postorder[postorderIndex - 1];
    if (!visited.count(right)) {
      visited.insert(right);
      node->right = new TreeNode{right};
    }
  }

  constructFromPrePostHelper(node->left, preorder, postorder, valueToIndexPre,
                             valueToIndexPost, visited);
  constructFromPrePostHelper(node->right, preorder, postorder, valueToIndexPre,
                             valueToIndexPost, visited);
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
  unordered_set<int> visited{};
  unordered_map<int, int> valueToIndexPost{};
  unordered_map<int, int> valueToIndexPre{};

  for (int i = 0; i < preorder.size(); i++) {
    valueToIndexPre[preorder[i]] = i;
  }

  for (int i = 0; i < postorder.size(); i++) {
    valueToIndexPost[postorder[i]] = i;
  }

  visited.insert(preorder[0]);
  TreeNode *root = new TreeNode{preorder[0]};
  constructFromPrePostHelper(root, preorder, postorder, valueToIndexPre,
                             valueToIndexPost, visited);

  return root;
}
