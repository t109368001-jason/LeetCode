/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
  struct ListNode* tmp;
  int              lengthA = 0;
  int              lengthB = 0;
  tmp                      = headA;
  while (tmp) {
    lengthA++;
    tmp = tmp->next;
  }
  tmp = headB;
  while (tmp) {
    lengthB++;
    tmp = tmp->next;
  }
  for (int i = lengthA; i < lengthB; i++) { headB = headB->next; }
  for (int i = lengthB; i < lengthA; i++) { headA = headA->next; }
  while (headA != NULL && headB != NULL) {
    if (headA == headB) { return headA; }
    headA = headA->next;
    headB = headB->next;
  }
  return false;
}

// first success O(m*n), O(1)
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//     struct ListNode* currentA = headA;
//     while(currentA) {
//         struct ListNode* currentB = headB;
//         while(currentB) {
//             if(currentA == currentB) {
//                 return currentA;
//             }
//             currentB = currentB->next;
//         }
//         currentA = currentA->next;
//     }
//     return NULL;
// }