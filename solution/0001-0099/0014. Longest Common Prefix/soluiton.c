char* longestCommonPrefix(char** strs, int strsSize) {
  int maxLen = strlen(strs[0]);
  for (int i = 1; i < strsSize; i++) {
    int len = 0;
    for (; len < maxLen; len++) {
      if (strs[0][len] != strs[i][len]) {
        len--;
        break;
      }
    }
    len++;
    maxLen = len < maxLen ? len : maxLen;
  }
  char* maxPrefix = calloc(maxLen + 1, sizeof(char));
  strncpy(maxPrefix, strs[0], maxLen);
  return maxPrefix;
}