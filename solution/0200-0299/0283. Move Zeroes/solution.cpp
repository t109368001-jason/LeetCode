class Solution {
 public:
  void moveZeroes(vector<int>& nums) { moveZeroesReplace(nums); }
  void moveZeroesReplace(vector<int>& nums) {
    int j;
    for (int num : nums) {
      if (num != 0) {
        nums[j++] = num;
      }
    }
    for (; j < nums.size(); j++) {
      nums[j] = 0;
    }
  }
  // first success, slow
  void moveZeroesSwap(vector<int>& nums) {
    auto l = nums.begin();
    auto r = nums.begin();
    while (l != nums.end() && r != nums.end()) {
      while (l != nums.end() && *l != 0) {
        l++;
      }
      r = l;
      while (r != nums.end() && *r == 0) {
        r++;
      }
      if (r == nums.end()) {
        break;
      }
      int tmp = *l;
      *l      = *r;
      *r      = tmp;
      l++;
    }
  }
};