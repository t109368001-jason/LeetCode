

int findComplement(int num) {
  int result = 0;
  int m      = 1;
  while (1) {
    if (!(num & 1)) {
      result += m;
    }
    num = num >> 1;
    if (num <= 0) {
      break;
    }
    m = m << 1;
  }
  return result;
}