/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct {
  struct ListNode* head;
  int              size;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
  Solution* solution = calloc(1, sizeof(Solution));
  solution->head     = head;
  solution->size     = 1;
  while (head->next) {
    solution->size++;
    head = head->next;
  }
  return solution;
}

int solutionGetRandom(Solution* obj) {
  int              index = rand() % obj->size;
  struct ListNode* tmp   = obj->head;
  for (int i = 0; i < index; i++) {
    tmp = tmp->next;
  }
  return tmp->val;
}

void solutionFree(Solution* obj) {
  free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/