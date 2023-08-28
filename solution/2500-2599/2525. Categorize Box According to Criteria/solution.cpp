class Solution {
 public:
  string categorizeBox(int length, int width, int height, int mass) {
    bool isBulky =
        (length >= 1e4) || (width >= 1e4) || (height >= 1e4) || ((long)length * (long)width * (long)height >= 1e9);
    bool isHeavy = (mass >= 100);
    if (isBulky && isHeavy) {
      return "Both";
    } else if (isBulky) {
      return "Bulky";
    } else if (isHeavy) {
      return "Heavy";
    }
    return "Neither";
  }
};