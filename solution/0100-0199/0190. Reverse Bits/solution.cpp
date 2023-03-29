class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = n & 0x1;
    for (int i = 1; i < sizeof(uint32_t) * 8; i++) {
      n >>= 1;
      result <<= 1;
      if (n & 0x1) {
        result |= 0x1;
      }
    }
    return result;
  }
};