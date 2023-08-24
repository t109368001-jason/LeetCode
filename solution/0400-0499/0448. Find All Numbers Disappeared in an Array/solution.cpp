class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    for (auto& c : nums) {
      while (nums[c - 1] != c) {
        swap(c, nums[c - 1]);
      }
    }
    for (int i = 1; i <= size(nums); i++) {
      if (i != nums[i - 1]) {
        result.push_back(i);
      }
    }
    return result;
  }
};