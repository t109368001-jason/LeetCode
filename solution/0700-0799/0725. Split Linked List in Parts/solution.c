/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
  *returnSize           = k;
  struct ListNode* tmp  = head;
  int              size = 0;
  while (tmp) {
    size++;
    tmp = tmp->next;
  }
  int n                    = size / k;
  int m                    = size - n * k;
  tmp                      = head;
  int               index  = 0;
  struct ListNode** result = calloc(k, sizeof(struct ListNode*));
  while (tmp) {
    struct ListNode* tmpNode = result[index];
    for (int i = 0; i < n; i++) {
      struct ListNode* newNode = calloc(1, sizeof(struct ListNode));
      if (tmpNode) {
        tmpNode->next = newNode;
        tmpNode       = newNode;
      } else {
        result[index] = newNode;
        tmpNode       = newNode;
      }
      tmpNode->val = tmp->val;
      tmp          = tmp->next;
    }
    if (m > 0) {
      struct ListNode* newNode = calloc(1, sizeof(struct ListNode));
      if (tmpNode) {
        tmpNode->next = newNode;
        tmpNode       = newNode;
      } else {
        result[index] = newNode;
        tmpNode       = newNode;
      }
      tmpNode->val = tmp->val;
      tmp          = tmp->next;
      m--;
    }
    index++;
  }
  return result;
}