/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
  if (!head) { return false; }
  if (!head->next) { return false; }
  struct ListNode* step1 = head;
  struct ListNode* step2 = head;
  while (step2 && step2->next) {
    step1 = step1->next;
    step2 = step2->next->next;
    if (step1 == step2) { return true; }
  }
  return false;
}