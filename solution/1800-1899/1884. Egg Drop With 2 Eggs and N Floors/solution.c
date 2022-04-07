int twoEggDrop(int n) {
  int result = 0;
  while (n > 0) {
    result++;
    n -= result;
  }
  return result;
}
