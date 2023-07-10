#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

ListNode *mergeKListsBruteForce(vector<ListNode *> &lists) {
  if (lists.empty()) {
    return nullptr;
  }
  ListNode *ans = lists[0];
  for (int i = 1; i < lists.size(); i++) {
    ans = mergeTwoLists(ans, lists[i]);
  }
  return ans;
}
