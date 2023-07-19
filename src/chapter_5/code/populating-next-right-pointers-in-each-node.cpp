class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connectHighEfficiency(Node *root) {
  if (root == nullptr) {
    return root;
  }

  Node *ptr = root;
  while (ptr->left != nullptr) {
    Node *head = ptr;
    while (head != nullptr) {
      // Situation 1: if they are connected by the same parent.
      head->left->next = head->right;

      // Situation 2: if they are connected by the different parent.
      // one parent is head, next parent is head->next
      if (head->next != nullptr) {
        head->right->next = head->next->left;
      }

      head = head->next;
    }
    ptr = ptr->left;
  }
  return root;
}

Node *connect(Node *root) { return connectHighEfficiency(root); }
