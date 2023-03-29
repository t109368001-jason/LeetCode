/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void addNode(struct TreeNode* node, int val, int depth) {
  if (depth == 2) {
    struct TreeNode* newLeft = calloc(1, sizeof(struct TreeNode));
    newLeft->val             = val;
    if (node->left) {
      newLeft->left = node->left;
    }
    node->left                = newLeft;
    struct TreeNode* newRight = calloc(1, sizeof(struct TreeNode));
    newRight->val             = val;
    if (node->right) {
      newRight->right = node->right;
    }
    node->right = newRight;
  } else if (depth > 2) {
    if (node->left) {
      addNode(node->left, val, depth - 1);
    }
    if (node->right) {
      addNode(node->right, val, depth - 1);
    }
  }
  return 0;
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
  if (depth == 1) {
    struct TreeNode* newRoot = calloc(1, sizeof(struct TreeNode));
    newRoot->val             = val;
    newRoot->left            = root;
    return newRoot;
  }
  addNode(root, val, depth);
  return root;
}