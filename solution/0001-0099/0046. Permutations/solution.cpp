class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteRecursive(0, nums, result);
    return result;
  }

  void permuteRecursive(int offset, vector<int>& nums, vector<vector<int>>& result) {
    if (offset >= nums.size()) {
      result.push_back(nums);
      return;
    }
    for (int i = offset; i < nums.size(); i++) {
      swap(nums[offset], nums[i]);
      permuteRecursive(offset + 1, nums, result);
      swap(nums[offset], nums[i]);
    }
  }

  // first success
  void permuteRecursive1(vector<int> prefix, vector<int> suffix, vector<vector<int>>& result) {
    if (suffix.empty()) {
      result.push_back(prefix);
      return;
    }
    for (size_t i = 0; i < suffix.size(); i++) {
      vector<int> p;
      p.assign(prefix.begin(), prefix.end());
      vector<int> s;
      s.assign(suffix.begin(), suffix.end());
      p.insert(p.begin(), suffix[i]);
      s.erase(s.begin() + i);
      permuteRecursive1(p, s, result);
    }
  }
};