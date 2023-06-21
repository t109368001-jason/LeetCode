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
  int kthSmallest(TreeNode* root, int k) { return kthSmallestRecursive(root, k); }

  int kthSmallestRecursive(TreeNode* root, int& k) {
    if (k == 0) {
      return root->val;
    }
    int res;
    if (root->left) {
      if ((res = kthSmallestRecursive(root->left, k)) != -1) {
        return res;
      }
    }
    k--;
    if (k == 0) {
      return root->val;
    }
    if (root->right) {
      if ((res = kthSmallestRecursive(root->right, k)) != -1) {
        return res;
      }
    }
    return -1;
  }
};