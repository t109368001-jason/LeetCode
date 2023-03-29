class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    return mySqrtRecursive(x, 0, x);
  }
  int mySqrtRecursive(int x, int l, int r) {
    int p = (l + r) / 2;
    // cout << l << ", " << r << "," << p << endl;
    if (l == p) {
      return l;
    }
    int y = x / p;
    if (y == p) {
      return p;
    }
    if (y < p) {
      return mySqrtRecursive(x, l, p);
    } else {
      return mySqrtRecursive(x, p, r);
    }
  }
};