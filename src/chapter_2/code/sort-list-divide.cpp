#include <memory>
#include <utility>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

pair<ListNode *, ListNode *> mergeTwoSortedList(ListNode *l1, ListNode *l2) {
  auto aux = make_unique<ListNode>(-1);
  ListNode *ptr = aux.get();
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val < l2->val) {
      ptr->next = l1;
      l1 = l1->next;
    } else {
      ptr->next = l2;
      l2 = l2->next;
    }
    ptr = ptr->next;
  }

  ptr->next = l1 ? l1 : l2;

  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  return make_pair(aux->next, ptr);
}

ListNode *sortList(ListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }

  auto aux = make_unique<ListNode>(-1, head);

  int length = 0;
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
    length++;
  }

  for (int subLength = 1; subLength < length; subLength *= 2) {
    ListNode *end = aux.get();
    ListNode *ptr = end->next;

    while (ptr != nullptr) {
      ListNode *pre = nullptr;
      ListNode *l1 = ptr;

      for (int i = 0; i < subLength && ptr != nullptr; i++) {
        pre = ptr;
        ptr = ptr->next;
      }

      pre->next = nullptr;

      ListNode *l2 = ptr;

      for (int i = 0; i < subLength && ptr != nullptr; i++) {
        pre = ptr;
        ptr = ptr->next;
      }

      pre->next = nullptr;

      auto &&[s, e] = mergeTwoSortedList(l1, l2);
      end->next = s;
      end = e;
    }
  }
  return aux->next;
}
