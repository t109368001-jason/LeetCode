/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    map<Node*, Node*> m;
    copyRandomListRecursive(head, m);
    return m[head];
  }

  void copyRandomListRecursive(Node* node, map<Node*, Node*>& m) {
    if (!node) {
      return;
    }
    Node* newNode = new Node(node->val);
    m[node]       = newNode;
    if (node->next) {
      copyRandomListRecursive(node->next, m);
      newNode->next = m[node->next];
    }
    if (node->random) {
      newNode->random = m[node->random];
    }
  }
};