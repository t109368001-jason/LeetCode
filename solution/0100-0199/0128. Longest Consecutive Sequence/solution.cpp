class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    sort(nums.begin(), nums.end());

    int n      = nums.size();
    int curr   = 1;
    int result = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] != nums[i]) {
        if (nums[i - 1] + 1 == nums[i]) {
          curr++;
        } else {
          result = max(result, curr);
          curr   = 1;
        }
      }
    }
    return max(result, curr);
  }
};