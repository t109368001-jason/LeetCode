/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode* left  = head;
  struct ListNode* right = head;
  for (int i = 0; i < n; i++) {
    right = right->next;
  }
  if (!right) {
    struct ListNode* tmp = head->next;
    free(head);
    return tmp;
  }
  while (right->next) {
    left  = left->next;
    right = right->next;
  }
  printf("%d\n", left->val);
  struct ListNode* tmp = left->next;
  // left->val = left->next->val;
  left->next = left->next->next;
  free(tmp);
  return head;
}