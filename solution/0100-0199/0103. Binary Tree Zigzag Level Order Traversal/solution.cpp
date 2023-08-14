/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  // intrative BFS 100%/86%
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> result;
    queue<TreeNode*>    nodesQueue;
    nodesQueue.push(root);
    bool left2Right = true;
    while (!nodesQueue.empty()) {
      int         size = nodesQueue.size();
      vector<int> tmp(size);
      for (int i = 0; i < size; i++) {
        TreeNode* node = nodesQueue.front();
        nodesQueue.pop();

        int index  = left2Right ? i : size - i - 1;
        tmp[index] = node->val;
        if (node->left) {
          nodesQueue.push(node->left);
        }
        if (node->right) {
          nodesQueue.push(node->right);
        }
      }
      left2Right = !left2Right;
      result.push_back(move(tmp));
    }
    return result;
  }

  // recursive DFS 100%/24%
  vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
    vector<list<int>> listResult;
    zigzagLevelOrder(0, root, listResult);
    vector<vector<int>> result;
    for (auto& l : listResult) {
      result.push_back(vector<int>(l.begin(), l.end()));
    }
    return result;
  }

  void zigzagLevelOrder(int level, TreeNode* root, vector<list<int>>& listResult) {
    if (!root) {
      return;
    }
    if (listResult.size() <= level) {
      listResult.resize(level + 1);
    }
    if (level % 2 == 0) {
      listResult[level].push_back(root->val);
    } else {
      listResult[level].push_front(root->val);
    }
    zigzagLevelOrder(level + 1, root->left, listResult);
    zigzagLevelOrder(level + 1, root->right, listResult);
  }
};