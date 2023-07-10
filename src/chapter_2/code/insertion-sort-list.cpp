#include <limits>
#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insertionSortList(ListNode *head) {
  auto aux = make_unique<ListNode>(numeric_limits<int>::min());

  ListNode *cur = head;
  while (cur != nullptr) {
    ListNode *next = cur->next;

    ListNode *pre = nullptr;
    ListNode *ptr = aux.get();
    while (ptr != nullptr) {
      if (ptr->val >= cur->val) {
        break;
      }
      pre = ptr;
      ptr = ptr->next;
    }

    pre->next = cur;
    cur->next = ptr;

    cur = next;
  }
  return aux->next;
}
