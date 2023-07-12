struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <stack>
#include <vector>
using namespace std;

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans{};
  stack<TreeNode *> st{};
  TreeNode *ptr = root;
  while (ptr != nullptr || !st.empty()) {
    while (ptr != nullptr) {
      st.push(ptr);
      ptr = ptr->left;
    }

    if (!st.empty()) {
      ans.push_back(st.top()->val);
      ptr = st.top()->right;
      st.pop();
    }
  }

  return ans;
}
