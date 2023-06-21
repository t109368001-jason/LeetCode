class Solution {
 public:
  // O(n), O(1)
  vector<int> productExceptSelf(vector<int>& nums) {
    int         n = nums.size();
    vector<int> result(n);
    result[0] = 1;
    for (int i = 1; i < n; i++) {
      result[i] = result[i - 1] * nums[i - 1];
      // nums = [a,b,c,d], result=[1,1*a, 1*a*b, 1*a*b*c]
    }
    int right = 1;
    // result=[(1)          , (1*a)        , (1*a*b)      , (1*a*b*c)*(1)], right=1*d
    // result=[(1)          , (1*a)        , (1*a*b)*(1*d), (1*a*b*c)*(1)], right=1*d*c
    // result=[(1)          , (1*a)*(1*d*c), (1*a*b)*(1*d), (1*a*b*c)*(1)], right=1*d*c*b
    // result=[(1)*(1*d*c*b), (1*a)*(1*d*c), (1*a*b)*(1*d), (1*a*b*c)*(1)], right=1*d*c*b*a
    for (int i = n - 1; i >= 0; i--) {
      result[i] *= right;
      right *= nums[i];
    }
    return result;
  }

  // first complete O(n^2), O(1)
  vector<int> productExceptSelf1(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < nums.size(); j++) {
        if (i == j) {
          continue;
        }
        result[i] *= nums[j];
      }
    }
    return result;
  }
};