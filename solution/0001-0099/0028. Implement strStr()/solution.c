

int strStr(char* haystack, char* needle) {
  if (!(*needle)) { return 0; }
  char* cursor = haystack;
  while (*cursor) {
    if (*cursor == *needle) {
      char* a = cursor + 1;
      char* b = needle + 1;

      while (*a && *b) {
        if (*a != *b) { break; }
        a++;
        b++;
      }
      if (!(*b)) { return cursor - haystack; }
      if (!(*a)) { return -1; }
    }
    cursor++;
  }
  return -1;
}