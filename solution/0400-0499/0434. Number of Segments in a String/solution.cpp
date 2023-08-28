class Solution {
 public:
  // sentinel value concise solution
  int countSegments(string s) {
    int res = 0;
    s.push_back(' ');
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == ' ' && s[i - 1] != ' ') {
        ++res;
      }
    }
    return res;
  }
  // flag 100%/91%
  int countSegments1(string s) {
    bool isLetter = false;
    int  count    = 0;
    for (char c : s) {
      if (c == ' ') {
        if (isLetter) {
          count++;
        }
        isLetter = false;
        continue;
      }
      isLetter = true;
    }
    if (!s.empty() && s[s.size() - 1] != ' ') {
      count++;
    }
    return count;
  }
};