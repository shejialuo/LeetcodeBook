#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  auto aux = make_unique<ListNode>(0, head);
  ListNode *slow = aux.get();
  ListNode *fast = aux.get();
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }
  while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;
  return aux->next;
}
