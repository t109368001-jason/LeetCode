bool isHappy(int n) {
  if (n == 1) {
    return true;
  }
  if (n == 2 || n == 4) {
    return false;
  }
  int sum = n;
  int tmp;
  do {
    tmp = sum;
    sum = 0;
    while (tmp > 0) {
      int x = tmp % 10;
      sum += x * x;
      tmp /= 10;
    }
    if (sum == 1) {
      return true;
    }
    if (sum == 2 || sum == 4) {
      return false;
    }
  } while (sum > 1);
  return true;
}