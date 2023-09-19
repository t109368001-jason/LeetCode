class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return true;
    }
    int l    = 0;
    int r    = num;
    int sqrt = (l + r) / 2;
    do {
      // cout << l << ", " << sqrt << ", " << r << endl;
      int quotient = num / sqrt;
      int rem      = num % sqrt;
      if (quotient == sqrt && rem == 0) {
        return true;
      } else if (quotient < sqrt) {
        r = sqrt;
      } else {
        l = sqrt;
      }
      sqrt = (l + r) / 2;
    } while (l != sqrt && r != sqrt);
    return false;
  }
};