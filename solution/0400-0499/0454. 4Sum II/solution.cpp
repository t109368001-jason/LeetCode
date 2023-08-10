class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    // key: num3+num4, value: combinations of num3+num4
    unordered_map<int, int> map;
    for (int num3 : nums3) {
      for (int num4 : nums4) {
        map[num3 + num4]++;
      }
    }
    int count = 0;
    for (int num1 : nums1) {
      for (int num2 : nums2) {
        count += map[-(num1 + num2)];
      }
    }
    return count;
  }
};