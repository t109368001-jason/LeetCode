/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connectAllLRtoRL(struct Node* left, struct Node* right) {
  if (left->right && right->left) {
    left->right->next = right->left;
    connectAllLRtoRL(left->right, right->left);
  }
}

struct Node* connect(struct Node* root) {
  if (!root) { return root; }
  if (root->left && root->right) {
    root->left->next = root->right;
    connect(root->left);
    connect(root->right);
    connectAllLRtoRL(root->left, root->right);
  }
  return root;
}