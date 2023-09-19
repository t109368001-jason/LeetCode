class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int rightSum = std::reduce(nums.begin(), nums.end());
    int leftSum  = 0;
    for (int i = 0; i < nums.size(); i++) {
      rightSum -= nums[i];
      if (leftSum == rightSum) {
        return i;
      }
      leftSum += nums[i];
    }
    return -1;
  }
  // 80%/5%
  int pivotIndex1(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int         n = nums.size();
    vector<int> dpL(n);
    vector<int> dpR(n);
    dpL[0]     = nums[0];
    dpR[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      dpL[i] = dpL[i - 1] + nums[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      dpR[i] = dpR[i + 1] + nums[i];
    }
    if (dpR[1] == 0) {
      return 0;
    }
    for (int i = 1; i < n - 1; i++) {
      if (dpL[i - 1] == dpR[i + 1]) {
        return i;
      }
    }
    if (dpL[n - 2] == 0) {
      return n - 1;
    }
    return -1;
  }
};