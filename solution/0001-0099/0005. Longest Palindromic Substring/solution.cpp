class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() == 1) {
      return s;
    }
    int maxIndex     = 0;
    int maxCount     = 0;
    int currentCount = 0;
    int left;
    int right;
    for (int i = 1; i < s.size(); i++) {
      if (i > 1 && s[i] == s[i - 2]) {
        currentCount = 3;
        left         = i - 3;
        right        = i + 1;
        for (; left >= 0 && right < s.size(); left--, right++) {
          if (s[left] != s[right]) {
            break;
          }
          currentCount += 2;
        }
        if (currentCount > maxCount) {
          maxIndex = left + 1;
          maxCount = currentCount;
        }
        currentCount = 0;
      }
      if (s[i] == s[i - 1]) {
        currentCount = 2;
        left         = i - 2;
        right        = i + 1;
        for (; left >= 0 && right < s.size(); left--, right++) {
          if (s[left] != s[right]) {
            break;
          }
          currentCount += 2;
        }
        if (currentCount > maxCount) {
          maxIndex = left + 1;
          maxCount = currentCount;
        }
        currentCount = 0;
      }
    }
    if (maxCount == 0) {
      return s.substr(0, 1);
    }
    return s.substr(maxIndex, maxCount);
  }
};