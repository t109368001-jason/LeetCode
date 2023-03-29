class Solution {
 public:
  int majorityElement(vector<int>& nums) { return majorityElementVote(nums); }
  // O(n), O(1)
  int majorityElementVote(vector<int>& nums) {
    int ele   = nums[0];
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0) ele = nums[i];
      count += (ele == nums[i]) ? 1 : -1;
    }
    return ele;
  }
  // first success, O(n), O(n)
  int majorityElementMap(vector<int>& nums) {
    map<int, int> countMap;
    for (int num : nums) {
      countMap[num]++;
    }
    int maxNum   = countMap.begin()->first;
    int maxCount = countMap.begin()->second;
    for (auto [num, count] : countMap) {
      if (count > maxCount) {
        maxNum   = num;
        maxCount = count;
      }
    }
    return maxNum;
  }
};