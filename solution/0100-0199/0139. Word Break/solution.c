bool wordBreak(char* s, char** wordDict, int wordDictSize) {
  int   sLen         = strlen(s);
  bool* matchedIndex = calloc(strlen(s) + 1, sizeof(bool));
  matchedIndex[sLen] = true;
  for (int i = sLen - 1; i >= 0; i--) {
    for (int wIndex = 0; wIndex < wordDictSize; wIndex++) {
      int wLen = strlen(wordDict[wIndex]);
      if (((i + wLen) <= sLen) && matchedIndex[i + wLen] && (strncmp(wordDict[wIndex], s + i, wLen) == 0)) {
        matchedIndex[i] = true;
        break;
      }
    }
  }
  return matchedIndex[0];
}