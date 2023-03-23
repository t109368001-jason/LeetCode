/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void addResult(int level, int val, int*** result, int* returnSize, int** returnColumnSizes) {
  if ((level + 1) >= *returnSize) {
    int   newReturnSize        = level + 1;
    int** newResult            = calloc(newReturnSize, sizeof(int*));
    int*  newReturnColumnSizes = calloc(newReturnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
      newResult[i]            = (*result)[i];
      newReturnColumnSizes[i] = (*returnColumnSizes)[i];
    }
    if (*result) {
      free(*result);
      *result = NULL;
    }
    if (*returnColumnSizes) {
      free(*returnColumnSizes);
      *returnColumnSizes = NULL;
    }
    *result            = newResult;
    *returnColumnSizes = newReturnColumnSizes;
    *returnSize        = newReturnSize;
  }
  int  newRowSizes = (*returnColumnSizes)[level] + 1;
  int* newRow      = calloc(newRowSizes, sizeof(int));
  for (int i = 0; i < (*returnColumnSizes)[level]; i++) { newRow[i] = (*result)[level][i]; }
  newRow[(*returnColumnSizes)[level]] = val;
  free((*result)[level]);
  (*result)[level]            = newRow;
  (*returnColumnSizes)[level] = newRowSizes;
}

void DFS(int              level,
         struct TreeNode* root,
         int***           result,
         int*             returnSize,
         int**            returnColumnSizes,
         void             callback(int level, int val, int** result, int* returnSize, int** returnColumnSizes)) {
  callback(level, root->val, result, returnSize, returnColumnSizes);
  if (root->left) { DFS(level + 1, root->left, result, returnSize, returnColumnSizes, addResult); }
  if (root->right) { DFS(level + 1, root->right, result, returnSize, returnColumnSizes, addResult); }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  *returnSize        = 0;
  *returnColumnSizes = NULL;
  if (!root) { return NULL; }
  int** result = NULL;
  DFS(0, root, &result, returnSize, returnColumnSizes, addResult);
  return result;
}