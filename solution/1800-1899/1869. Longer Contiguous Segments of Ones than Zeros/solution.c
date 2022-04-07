

bool checkZeroOnes(char* s) {
  int   onesCount  = 0;
  int   zerosCount = 0;
  char* l          = s;
  s++;
  while (1) {
    if (!(*s) || *s != *l) {
      int count = s - l;
      if (*l == '1') {
        if (count > onesCount) { onesCount = count; }
      } else {
        if (count > zerosCount) { zerosCount = count; }
      }
      l = s;
      if (!(*s)) { break; }
    }
    s++;
  }
  printf("%d, %d\n", onesCount, zerosCount);
  return onesCount > zerosCount;
}