

int minSteps(char* s, char* t) {
  int* countS = calloc(26, sizeof(int));
  int* countT = calloc(26, sizeof(int));
  while (*s) {
    countS[*s - 'a']++;
    s++;
  }
  while (*t) {
    countT[*t - 'a']++;
    t++;
  }

  int result = 0;
  for (int i = 0; i < 26; i++) {
    result += abs(countS[i] - countT[i]);
  }
  return result / 2;
}