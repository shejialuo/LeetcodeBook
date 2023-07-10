struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  ListNode *ptr = head;
  while (ptr != nullptr) {
    ListNode *next = ptr->next;
    while (next != nullptr && ptr->val == next->val) {
      next = next->next;
    }
    ptr->next = next;
    ptr = next;
  }

  return head;
}
