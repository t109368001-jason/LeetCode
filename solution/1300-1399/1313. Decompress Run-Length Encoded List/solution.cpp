class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i += 2) {
      fill_n(back_inserter(result), nums[i], nums[i + 1]);
    }
    return result;
  }
};