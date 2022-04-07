

int totalMoney(int n) {
  int result = 0;
  int m      = 0;
  while (n > 0) {
    if (n >= 7) {
      result += 28 + m * 7;
      n -= 7;
      m++;
    } else {
      while (n > 0) {
        result += n + m;
        n--;
      }
    }
  }
  return result;
}