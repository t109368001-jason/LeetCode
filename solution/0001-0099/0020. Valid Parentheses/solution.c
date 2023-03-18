

bool isValid(char* s) {
  char* buffer      = calloc(strlen(s) + 1, sizeof(char));
  int   bufferIndex = -1;
  while (*s) {
    // printf("%s, %s\n", s, buffer);
    switch (*s) {
      case '(':
      case '[':
      case '{':
        buffer[bufferIndex + 1] = *s;
        bufferIndex++;
        break;
      case ')':
        if (bufferIndex < 0 || buffer[bufferIndex] != '(') {
          free(buffer);
          return false;
        } else {
          buffer[bufferIndex] = '\0';
          bufferIndex--;
        }
        break;
      case ']':
        if (bufferIndex < 0 || buffer[bufferIndex] != '[') {
          free(buffer);
          return false;
        } else {
          buffer[bufferIndex] = '\0';
          bufferIndex--;
        }
        break;
      case '}':
        if (bufferIndex < 0 || buffer[bufferIndex] != '{') {
          free(buffer);
          return false;
        } else {
          buffer[bufferIndex] = '\0';
          bufferIndex--;
        }
        break;
    }
    s++;
  }
  free(buffer);
  return bufferIndex == -1;
}