#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroupHelper(ListNode *start, ListNode *end) {
  ListNode *nextStart = start->next;

  ListNode *pre = start->next;
  ListNode *cur = pre->next;
  while (cur != end) {
    ListNode *next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  start->next->next = end;
  start->next = pre;

  return nextStart;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  auto aux = make_unique<ListNode>(-1, head);
  ListNode *ptr = aux.get();

  while (ptr != nullptr) {
    int length = 0;
    ListNode *end = ptr;
    for (; length < k + 1 && end != nullptr; length++) {
      end = end->next;
    }

    if (end == nullptr && length < k + 1) {
      break;
    }

    ptr = reverseKGroupHelper(ptr, end);
  }
  return aux->next;
}