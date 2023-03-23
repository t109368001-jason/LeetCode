int titleToNumber(char* columnTitle) {
  int sum = 0;
  while (*columnTitle != '\0') {
    sum *= 26;
    sum += *columnTitle - '@';
    columnTitle++;
  }
  return sum;
}