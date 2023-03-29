int romainToInt(char c, char** s) {
  if (**s == '\0') {
    return 0;
  }
  int count = 0;
  while (**s == c) {
    count++;
    (*s)++;
  }
  bool hasFlowing = **s != '\0' && (*s)[1] == c;
  if (hasFlowing) {
    (*s)++;
    (*s)++;
  }
  switch (c) {
    case 'M': return count * 1000 + (hasFlowing ? 900 : 0);
    case 'D': return count * 500 + (hasFlowing ? 400 : 0);
    case 'C': return count * 100 + (hasFlowing ? 90 : 0);
    case 'L': return count * 50 + (hasFlowing ? 40 : 0);
    case 'X': return count * 10 + (hasFlowing ? 9 : 0);
    case 'V': return count * 5 + (hasFlowing ? 4 : 0);
    case 'I': return count * 1;
  }
  return 0;
}

int romanToInt(char* s) {
  int result = 0;
  result += romainToInt('M', &s);
  result += romainToInt('D', &s);
  result += romainToInt('C', &s);
  result += romainToInt('L', &s);
  result += romainToInt('X', &s);
  result += romainToInt('V', &s);
  result += romainToInt('I', &s);
  return result;
}