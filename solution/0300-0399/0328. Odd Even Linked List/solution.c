/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
  if (!head) {
    return head;
  }
  struct ListNode* head1 = NULL;
  struct ListNode* tail1 = NULL;
  struct ListNode* head2 = NULL;
  struct ListNode* tail2 = NULL;

  struct ListNode* current = head;
  char             flag    = 1;
  while (current) {
    if (flag) {
      if (!tail1) {
        head1 = current;
        tail1 = current;
      } else {
        tail1->next = current;
        tail1       = current;
      }
      flag = 0;
    } else {
      if (!tail2) {
        head2 = current;
        tail2 = current;
      } else {
        tail2->next = current;
        tail2       = current;
      }
      flag = 1;
    }
    current = current->next;
  }
  tail1->next = head2;
  if (tail2) {
    tail2->next = NULL;
  }
  return head1;
}