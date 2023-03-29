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
  int maxDepth(TreeNode* root) { return maxDepthRecursive(root); }
  int maxDepthRecursive(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return max(maxDepthRecursive(root->left), maxDepthRecursive(root->right)) + 1;
  }
};