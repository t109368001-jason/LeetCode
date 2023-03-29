class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int  c  = 0;
    auto it = digits.rbegin();
    (*it)++;
    for (; it < digits.rend(); it++) {
      if (c) {
        (*it)++;
        c = 0;
      }
      if (*it >= 10) {
        *it -= 10;
        c = 1;
      }
    }
    if (c) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};