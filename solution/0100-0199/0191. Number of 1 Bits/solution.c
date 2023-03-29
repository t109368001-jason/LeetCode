int hammingWeight(uint32_t n) {
  int      result = 0;
  uint32_t mask   = 0x1;
  for (int i = 0; i < sizeof(n) * 8; i++) {
    if (n & mask) {
      result++;
    }
    mask = mask << 1;
  }
  return result;
}