#include <stack>
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

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans{};
  stack<TreeNode *> st{};
  TreeNode *pre{nullptr}, *ptr = root;
  while (ptr != nullptr || !st.empty()) {
    while (ptr != nullptr) {
      st.push(ptr);
      ptr = ptr->left;
    }

    if (!st.empty()) {
      TreeNode *cur = st.top();
      if (cur->right == nullptr || cur->right == pre) {
        ans.push_back(cur->val);
        pre = cur;
        st.pop();
      } else {
        ptr = cur->right;
      }
    }
  }
  return ans;
}
