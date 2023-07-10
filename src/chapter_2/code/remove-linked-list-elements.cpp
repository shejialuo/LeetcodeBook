#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) {
  auto aux = std::make_unique<ListNode>(0, head);
  ListNode *ptr = aux.get();
  while (ptr != nullptr) {
    if (ptr->next != nullptr && ptr->next->val == val) {
      ptr->next = ptr->next->next;
    } else {
      ptr = ptr->next;
    }
  }
  return aux->next;
}
