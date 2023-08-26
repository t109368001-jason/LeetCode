class Solution {
 public:
  int lengthOfLastWord(string s) {
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (count > 0) {
        if (s[i] == ' ') {
          return count;
        }
        count++;
      } else {
        if (s[i] != ' ') {
          count = 1;
        }
      }
    }
    return count;
  }
};