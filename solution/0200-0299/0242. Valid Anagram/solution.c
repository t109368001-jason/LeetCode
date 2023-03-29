

bool isAnagram(char* s, char* t) {
  int* count = calloc(26, sizeof(int));
  while (*s) {
    count[*s - 'a']++;
    s++;
  }
  while (*t) {
    count[*t - 'a']--;
    t++;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i]) {
      return false;
    }
  }
  return true;
}