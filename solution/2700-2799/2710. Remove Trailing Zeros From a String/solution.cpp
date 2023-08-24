class Solution {
 public:
  string removeTrailingZeros(string num) {
    int i = num.size() - 1;
    for (; i >= 0; i--) {
      if (num[i] != '0') {
        break;
      }
    }
    return num.substr(0, i + 1);
  }
};