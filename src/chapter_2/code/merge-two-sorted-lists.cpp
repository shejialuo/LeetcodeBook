#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  auto aux = make_unique<ListNode>(-1);
  ListNode *p = aux.get();
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      p->next = list1;
      list1 = list1->next;
    } else {
      p->next = list2;
      list2 = list2->next;
    }
    p = p->next;
  }
  p->next = list1 == nullptr ? list2 : list1;

  return aux->next;
}
