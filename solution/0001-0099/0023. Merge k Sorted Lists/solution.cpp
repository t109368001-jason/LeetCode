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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);
    ListNode                                                              holder(0, nullptr);
    ListNode*                                                             curr = &holder;
    for (int i = 0; i < lists.size(); i++) {
      if (!lists[i]) {
        lists.erase(lists.begin() + i);
        i--;
        continue;
      }
      q.push(lists[i]);
      lists[i] = lists[i]->next;
    }
    while (!q.empty()) {
      curr->next = q.top();
      curr       = curr->next;
      q.pop();
      if (curr->next) {
        q.push(curr->next);
      }
    }
    curr->next = nullptr;
    return holder.next;
  }
};