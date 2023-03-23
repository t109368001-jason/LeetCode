/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
  if (!list1 && !list2) { return NULL; }
  struct ListNode* head    = calloc(1, sizeof(struct ListNode));
  struct ListNode* current = head;
  if (!list2) {
    current->val = list1->val;
    list1        = list1->next;
  } else if (!list1) {
    current->val = list2->val;
    list2        = list2->next;
  } else if (list1->val <= list2->val) {
    current->val = list1->val;
    list1        = list1->next;
  } else {
    current->val = list2->val;
    list2        = list2->next;
  }
  while (list1 || list2) {
    struct ListNode* next = calloc(1, sizeof(struct ListNode));
    if (list1 && list2) {
      if (list1->val <= list2->val) {
        next->val = list1->val;
        list1     = list1->next;
      } else {
        next->val = list2->val;
        list2     = list2->next;
      }
      current->next = next;
      current       = next;
      continue;
    }
    if (list1) {
      next->val     = list1->val;
      list1         = list1->next;
      current->next = next;
      current       = next;
      continue;
    }
    next->val     = list2->val;
    list2         = list2->next;
    current->next = next;
    current       = next;
  }
  return head;
}