class Solution {
 public:
  int search(vector<int>& nums, int target) { return searchRecursive(0, nums.size() - 1, nums, target); }

  int searchRecursive(int l, int r, vector<int>& nums, int target) {
    if (nums[l] == target) {
      return l;
    } else if (nums[r] == target) {
      return r;
    }
    if (r - l < 2) {
      return -1;
    }
    int p = (l + r) / 2;
    if (nums[p] == target) {
      return p;
    }
    if (nums[p] > nums[l]) {
      if (nums[l] < target && target < nums[p]) {
        return searchRecursive(l + 1, p, nums, target);
      } else {
        return searchRecursive(p, r - 1, nums, target);
      }
    } else {
      if (nums[p] < target && target < nums[r]) {
        return searchRecursive(p, r - 1, nums, target);
      } else {
        return searchRecursive(l + 1, p, nums, target);
      }
    }
    return -1;
  }
};