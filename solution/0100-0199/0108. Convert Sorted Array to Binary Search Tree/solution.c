/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  if (numsSize == 0) { return 0; }
  struct TreeNode* root   = calloc(1, sizeof(struct TreeNode));
  int              center = numsSize / 2;
  root->val               = nums[center];
  root->left              = sortedArrayToBST(nums, center);
  root->right             = sortedArrayToBST(nums + center + 1, numsSize - center - 1);
  return root;
}