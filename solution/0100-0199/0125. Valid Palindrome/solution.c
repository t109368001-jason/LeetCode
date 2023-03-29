bool isAlphanumeric(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  }
  if ('A' <= c && c <= 'Z') {
    return true;
  }
  if ('a' <= c && c <= 'z') {
    return true;
  }
  return false;
}

char lower(char c) {
  if ('A' <= c && c <= 'Z') {
    return c - 'A' + 'a';
  }
  return c;
}

bool isPalindrome(char* s) {
  char* l = s;
  char* r = s + strlen(s) - 1;

  while (l < r) {
    while (l < r && !isAlphanumeric(*l)) {
      l++;
    }
    while (l < r && !isAlphanumeric(*r)) {
      r--;
    }
    if (l >= r) {
      return true;
    }
    if (lower(*l) != lower(*r)) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}