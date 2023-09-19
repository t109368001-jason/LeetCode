class Solution {
 public:
  int minimumRightShifts(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    int lastDesc  = -1;
    int descCount = 0;
    if (nums[n - 1] > nums[0]) {
      lastDesc = 0;
      descCount++;
    }
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] > nums[i]) {
        lastDesc = i;
        descCount++;
      }
    }
    if (descCount == 0) {
      return 0;
    } else if (descCount > 1) {
      return -1;
    } else if (lastDesc == 0) {
      return 0;
    }
    return n - lastDesc;
  }
};