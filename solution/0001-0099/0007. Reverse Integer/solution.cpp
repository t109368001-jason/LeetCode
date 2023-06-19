class Solution {
 public:
  int reverse(int x) {
    bool positive = x > 0;
    int  result   = 0;
    while (x) {
      int lsb = abs(x % 10);
      if (result > 214748364 || (result == 214748364 && lsb > 7)) {
        return 0;
      }
      result *= 10;
      result += lsb;
      x /= 10;
    }
    if (positive) {
      return result;
    } else {
      return -result;
    }
  }
};