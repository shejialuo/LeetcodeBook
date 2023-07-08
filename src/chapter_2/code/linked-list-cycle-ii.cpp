struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
  ListNode *slowPointer = head;
  ListNode *fastPointer = head;
  if (slowPointer == nullptr) {
    return head;
  }

  while (fastPointer) {
    fastPointer = fastPointer->next;
    if (fastPointer != nullptr) {
      slowPointer = slowPointer->next;
      fastPointer = fastPointer->next;
    }

    if (fastPointer == slowPointer) {
      slowPointer = head;
      while (fastPointer != slowPointer) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
      }
      return slowPointer;
    }
  }
  return nullptr;
}
