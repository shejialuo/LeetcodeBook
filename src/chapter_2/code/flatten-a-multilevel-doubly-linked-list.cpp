class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

Node *flattenHelper(Node *node) {
  Node *ptr = node, *pre = nullptr;

  while (ptr != nullptr) {
    if (ptr->child != nullptr) {
      Node *next = ptr->next;
      ptr->next = ptr->child;
      ptr->child->prev = ptr;

      Node *end = flattenHelper(ptr->child);
      ptr->child = nullptr;

      end->next = next;
      if (next != nullptr) {
        next->prev = end;
      }
      pre = end;
      ptr = next;
    } else {
      pre = ptr;
      ptr = ptr->next;
    }
  }
  return pre;
}

Node *flatten(Node *head) {
  flattenHelper(head);
  return head;
}
