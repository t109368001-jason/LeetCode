/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
  struct ListNode* result = head;
  while (head->next) {
    result = result->next;
    head   = head->next;
    if (head->next) {
      ;
      head = head->next;
    }
  }
  return result;
}