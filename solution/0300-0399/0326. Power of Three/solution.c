bool isPowerOfThree(int n) {
  if (n == 1) { return true; }
  if (n == 3) { return true; }
  if (-3 < n && n < 3) { return false; }
  if (n % 3 != 0) { return false; }
  return isPowerOfThree(n / 3);
}