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
  // 98%/81%
  int maxSum_ = INT_MIN;

 public:
  int maxPathSum(TreeNode* root) {
    max_gain(root);
    return maxSum_;
  }
  int max_gain(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int l      = max(max_gain(root->left), 0);
    int r      = max(max_gain(root->right), 0);
    int maxSum = root->val + l + r;
    maxSum_    = max(maxSum_, maxSum);
    return root->val + max(l, r);
  }

  // first success 93%/12%
  int maxPathSum1(TreeNode* root) {
    int localMax  = root->val;
    int globalMax = maxPathSumPair(root, localMax);
    return max(globalMax, localMax);
  }

  int maxPathSumPair(TreeNode* root, int& localMax) {
    if (!root->left && !root->right) {
      localMax = max(localMax, root->val);
      return root->val;
    }
    int globalMax = root->val;
    int lMax;
    int rMax;
    if (root->left) {
      lMax = maxPathSumPair(root->left, localMax);
      // cout << root->val << " l " << lMax << ", " << localMax << endl;
      globalMax = max(globalMax, root->val + lMax);
    }
    if (root->right) {
      rMax = maxPathSumPair(root->right, localMax);
      // cout << root->val << " r " << rMax << ", " << localMax << endl;
      globalMax = max(globalMax, root->val + rMax);
    }
    localMax = max(localMax, globalMax);
    if (root->left && root->right) {
      localMax = max(localMax, root->val + lMax + rMax);
    }

    // cout << root->val << " " << globalMax << ", " << localMax << endl;
    return globalMax;
  }
};