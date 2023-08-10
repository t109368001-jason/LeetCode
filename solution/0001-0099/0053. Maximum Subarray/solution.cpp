class Solution {
 public:
  // Kadane's Algorithm 97%/80%
  int maxSubArray(vector<int>& nums) {
    int n       = nums.size();
    int maxSum  = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
      currSum += nums[i];
      maxSum  = max(maxSum, currSum);
      currSum = max(currSum, 0);
    }
    return maxSum;
  }
  // DP 94%, 6%
  int maxSubArray1(vector<int>& nums) {
    int dp[nums.size()];
    dp[0]      = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp[i]  = nums[i] + max(dp[i - 1], 0);
      result = max(result, dp[i]);
    }
    return result;
  }
};