int lengthOfLongestSubstring(char* s) {
  int   result = 0;
  char* b      = s;
  char* c      = s + 1;
  while (*s != 0) {
    if (*c == 0) {
      if ((c - s) > result) {
        result = c - s;
      }
      break;
    }
    while (b < c) {
      if (*b == *c) {
        break;
      }
      b++;
    }
    if (b != c) {
      s++;
      b = s;
      if (s == c) {
        c++;
      }
    } else {
      if ((c - s + 1) > result) {
        result = c - s + 1;
      }
      c++;
      b = s;
    }
  }
  return result;
}