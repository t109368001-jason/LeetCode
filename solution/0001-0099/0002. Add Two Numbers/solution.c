/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* result  = calloc(1, sizeof(struct ListNode));
  struct ListNode* current = result;
  int              sum;
  while (l1 || l2) {
    sum = current->val;
    if (l1) {
      sum += l1->val;
    }
    if (l2) {
      sum += l2->val;
    }
    current->val = sum % 10;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
    if (l1 || l2 || (sum >= 10)) {
      current->next = calloc(1, sizeof(struct ListNode));
      current       = current->next;
      current->val  = sum / 10;
    }
  }
  return result;
}