/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
  }
  // first success 92%/11%
  TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    queue<TreeNode*> pQueue;
    queue<TreeNode*> qQueue;

    find(root, p, q, pQueue, qQueue);

    while (pQueue.size() > qQueue.size()) {
      pQueue.pop();
    }
    while (qQueue.size() > pQueue.size()) {
      qQueue.pop();
    }
    while (pQueue.front() != qQueue.front()) {
      pQueue.pop();
      qQueue.pop();
    }
    return pQueue.front();
  }

  pair<bool, bool> find(TreeNode* root, TreeNode* p, TreeNode* q, queue<TreeNode*>& pQueue, queue<TreeNode*>& qQueue) {
    if (!root) {
      return {false, false};
    }
    pair<bool, bool> found  = {false, false};
    pair<bool, bool> foundL = find(root->left, p, q, pQueue, qQueue);
    pair<bool, bool> foundR = find(root->right, p, q, pQueue, qQueue);
    found.first |= root == p || foundL.first || foundR.first;
    found.second |= root == q || foundL.second || foundR.second;
    if (found.first) {
      // cout << "p " << root->val << endl;
      pQueue.push(root);
    }
    if (found.second) {
      // cout << "q " << root->val << endl;
      qQueue.push(root);
    }
    return found;
  }
};