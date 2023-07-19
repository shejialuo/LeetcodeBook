

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *sortedListToBST(ListNode *head) {
  // End case
  if (head == nullptr) {
    return nullptr;
  }

  if (head->next == nullptr) {
    TreeNode *node = new TreeNode(head->val);
    return node;
  }

  ListNode *slow = head, *fast = head, *pre = nullptr;

  // Use slow and fast pointer to find the middle.
  while (fast != nullptr) {
    fast = fast->next;
    if (fast != nullptr) {
      fast = fast->next;
      pre = slow;
      slow = slow->next;
    }
  }
  TreeNode *node = new TreeNode(slow->val);
  pre->next = nullptr;
  node->left = sortedListToBST(head);
  node->right = sortedListToBST(slow->next);
  return node;
}
