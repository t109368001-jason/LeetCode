class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int>         tmp;
    subsetsRecursive(0, tmp, nums, result);
    return result;
  }

  void subsetsRecursive(int offset, vector<int>& current, vector<int>& nums, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = offset; i < nums.size(); i++) {
      current.push_back(nums[i]);
      subsetsRecursive(i + 1, current, nums, result);
      current.pop_back();
    }
  }
};