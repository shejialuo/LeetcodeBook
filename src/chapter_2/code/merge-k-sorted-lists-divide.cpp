#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

ListNode *mergeKListsDivideAndConquer(vector<ListNode *> &lists, int start,
                                      int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    ListNode *left = mergeKListsDivideAndConquer(lists, start, mid);
    ListNode *right = mergeKListsDivideAndConquer(lists, mid + 1, end);
    return mergeTwoLists(left, right);
  } else if (start == end) {
    return lists[start];
  } else {
    return nullptr;
  }
}