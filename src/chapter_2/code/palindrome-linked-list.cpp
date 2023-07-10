struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *findMidNode(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *pre = nullptr;

  int length = 0;

  while (fast != nullptr) {
    fast = fast->next;
    length++;
    if (fast != nullptr) {
      length++;
      fast = fast->next;
      pre = slow;
      slow = slow->next;
    }
  }

  if (pre != nullptr) {
    pre->next = nullptr;
  }

  if (length % 2 != 0) {
    return slow->next;
  } else {
    return slow;
  }
}

ListNode *reverseList(ListNode *head) {
  ListNode *ptr = head;
  ListNode *pre = nullptr;

  while (ptr != nullptr) {
    ListNode *next = ptr->next;
    ptr->next = pre;
    pre = ptr;
    ptr = next;
  }

  return pre;
}

bool isPalindrome(ListNode *head) {
  if (head->next == nullptr) {
    return true;
  }

  ListNode *ptr1 = head;
  ListNode *ptr2 = reverseList(findMidNode(head));

  while (ptr1 != nullptr) {
    if (ptr1->val != ptr2->val) {
      return false;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return true;
}
