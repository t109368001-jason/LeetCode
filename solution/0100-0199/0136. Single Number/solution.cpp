class Solution {
 public:
  int singleNumber(vector<int>& nums) { return singleNumberXor(nums); }
  int singleNumberXor(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
      ans ^= num;
    }
    return ans;
  }
  // O(n), O(n)
  int singleNumberMap(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
      countMap[num]++;
    }
    for (auto [num, count] : countMap) {
      if (count == 1) {
        return num;
      }
    }
    return -1;
  }
};