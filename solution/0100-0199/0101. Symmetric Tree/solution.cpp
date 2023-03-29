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
  bool isSymmetric(TreeNode* root) { return isSymmetricRecursive(root->left, root->right); }
  bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
    if ((!left) ^ (!right)) {
      return false;
    }
    if (!left) {
      return true;
    }
    if (left->val != right->val) {
      return false;
    }
    return isSymmetricRecursive(left->left, right->right) && isSymmetricRecursive(left->right, right->left);
  }
  // slow then recursive
  bool isSymmetricIter(TreeNode* root) {
    if (!root->left && !root->right) {
      return true;
    }
    vector<pair<TreeNode*, TreeNode*>> todo;
    todo.emplace_back(root->left, root->right);
    while (!todo.empty()) {
      auto it = todo.back();
      todo.pop_back();
      if ((!it.first) ^ (!it.second)) {
        return false;
      }
      if (it.first) {
        if (it.first->val != it.second->val) {
          return false;
        }
        todo.emplace_back(it.first->left, it.second->right);
        todo.emplace_back(it.first->right, it.second->left);
      }
    }
    return true;
  }
};