class Solution {
 public:
  string removeDigit(string number, char digit) {
    int n = number.size();
    int lastIndex;
    for (int i = 0; i < n - 1; i++) {
      if (number[i] == digit) {
        lastIndex = i;
        if (number[i] < number[i + 1]) {
          return number.substr(0, lastIndex) + number.substr(lastIndex + 1);
        }
      }
    }
    if (number[n - 1] == digit) {
      lastIndex = n - 1;
    }
    return number.substr(0, lastIndex) + number.substr(lastIndex + 1);
  }
};