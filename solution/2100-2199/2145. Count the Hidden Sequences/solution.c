

int numberOfArrays(int* differences, int differencesSize, int lower, int upper) {
  long min     = 0;
  long max     = 0;
  long current = 0;
  for (int i = 0; i < differencesSize; i++) {
    current += differences[i];
    if (current < min) {
      min = current;
    }
    if (current > max) {
      max = current;
    }
  }
  int result = (upper - lower) - (max - min) + 1;
  if (result < 0) {
    return 0;
  }
  return result;
}