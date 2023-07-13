/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include <memory>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  auto ans = make_unique<ListNode>(-1);
  ListNode *rear = ans.get();
  ListNode *p1 = l1;
  ListNode *p2 = l2;

  int C = 0;

  while (p1 != nullptr || p2 != nullptr) {
    int num1 = p1 ? p1->val : 0;
    int num2 = p2 ? p2->val : 0;

    int sum = (num1 + num2 + C) % 10;
    C = (num1 + num2 + C) / 10;
    ListNode *node = new ListNode(sum);
    rear->next = node;
    rear = node;

    if (p1 != nullptr)
      p1 = p1->next;
    if (p2 != nullptr)
      p2 = p2->next;
  }

  if (C != 0) {
    ListNode *node = new ListNode(C);
    rear->next = node;
  }

  return ans->next;
}
