int climbStairsRecursive(int n, int a, int b) {
  if (n == 1) {
    return b;
  }
  if (n == 2) {
    return a + b;
  }
  return climbStairsRecursive(n - 1, b, a + b);
}

int climbStairs(int n) {
  return climbStairsRecursive(n + 1, 0, 1);
}