class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int _max       = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) {
        swap(currentMax, currentMin);
      }
      currentMax = max(nums[i], currentMax * nums[i]);
      currentMin = min(nums[i], currentMin * nums[i]);

      _max = max(_max, currentMax);
    }
    return _max;
  }
};