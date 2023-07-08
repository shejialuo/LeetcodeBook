struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
  ListNode *slowPointer = head;
  ListNode *fastPointer = head;
  if (slowPointer == nullptr) {
    return false;
  }
  while (fastPointer) {
    fastPointer = fastPointer->next;
    if (fastPointer != nullptr) {
      slowPointer = slowPointer->next;
      fastPointer = fastPointer->next;
    }
    if (slowPointer == fastPointer) {
      return true;
    }
  }
  return false;
}
