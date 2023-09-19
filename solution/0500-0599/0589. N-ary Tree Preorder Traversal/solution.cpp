/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (!root) {
      return {};
    }
    vector<int>  result;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      auto top = s.top();
      s.pop();
      result.push_back(top->val);
      for (auto it = top->children.rbegin(); it != top->children.rend(); ++it) {
        if (*it) {
          s.push(*it);
        }
      }
    }
    return result;
  }
};