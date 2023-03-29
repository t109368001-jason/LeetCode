/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* last    = head;
    ListNode* current = head->next;
    last->next        = nullptr;
    while (current->next) {
      ListNode* tmp = current->next;
      current->next = last;
      last          = current;
      current       = tmp;
    }
    current->next = last;
    return current;
  }
};