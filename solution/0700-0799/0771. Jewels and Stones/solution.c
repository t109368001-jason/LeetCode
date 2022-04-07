

int numJewelsInStones(char* jewels, char* stones) {
  char* buffer      = calloc(52, sizeof(char));
  char  lowerOffset = 'a' - 26;
  while (*stones) {
    if (*stones > 'Z') {
      buffer[*stones - lowerOffset]++;
    } else {
      buffer[*stones - 'A']++;
    }
    stones++;
  }
  int result = 0;
  while (*jewels) {
    if (*jewels > 'Z') {
      result += buffer[*jewels - lowerOffset];
    } else {
      result += buffer[*jewels - 'A'];
    }
    jewels++;
  }
  return result;
}