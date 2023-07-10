struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k) {

  // Corner case
  if (head == nullptr || k == 0) {
    return head;
  }

  int length = 0;
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
    length++;
  }

  // Do Nothing
  int num = length - k % length;
  if (num % length == 0) {
    return head;
  }

  ListNode *newHead = head;
  ListNode *ptr = nullptr;

  for (int i = 0; i < num; i++) {
    ptr = newHead;
    newHead = newHead->next;
  }

  ptr->next = nullptr;

  ptr = newHead;
  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  ptr->next = head;

  return newHead;
}
