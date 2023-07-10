struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head) {
  ListNode **p = &head;
  ListNode *adjacentFirst{};
  ListNode *adjacentSecond{};
  while ((adjacentFirst = *p) && (adjacentSecond = (*p)->next)) {
    // Here we do normal LinkNode swap
    adjacentFirst->next = adjacentSecond->next;
    adjacentSecond->next = adjacentFirst;

    // Now we make current pointer to ListNode* to
    // be the value of the `adjacentSecond`.
    *p = adjacentSecond;
    p = &(adjacentFirst->next);
  }
  return head;
}