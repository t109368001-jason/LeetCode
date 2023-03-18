/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
  if (preorderSize == 0 || inorderSize == 0) { return NULL; }
  struct TreeNode* root = calloc(1, sizeof(struct TreeNode));
  root->val             = *preorder;
  int leftSize          = 0;
  while (leftSize < preorderSize && *preorder != inorder[leftSize]) { leftSize++; }
  if (leftSize != 0) { root->left = buildTree(preorder + 1, leftSize, inorder, leftSize); }
  leftSize++;
  root->right = buildTree(preorder + leftSize, preorderSize - leftSize, inorder + leftSize, inorderSize - leftSize);
  return root;
}