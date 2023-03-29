int trailingZeroes(int n) {
  int add = 0;
  if (n > 3125) {
    return (n / 3125) * trailingZeroes(3125) + trailingZeroes(n % 3125) + add;
  }
  if (n == 3125) {
    add++;
  }
  if (n > 625) {
    return (n / 625) * trailingZeroes(625) + trailingZeroes(n % 625) + add;
  }
  if (n == 625) {
    add++;
  }
  if (n > 125) {
    return (n / 125) * trailingZeroes(125) + trailingZeroes(n % 125) + add;
  }
  if (n == 125) {
    add++;
  }
  if (n > 25) {
    return (n / 25) * trailingZeroes(25) + trailingZeroes(n % 25) + add;
  }
  if (n == 25) {
    add++;
  }
  if (n > 5) {
    return (n / 5) * trailingZeroes(5) + trailingZeroes(n % 5) + add;
  }
  if (n == 5) {
    add++;
  }
  return add;
}