void reverseString(char* s, int sSize) {
  char  tmp;
  char* l = s;
  char* r = s + sSize - 1;
  while (l < r) {
    tmp = *l;
    *l  = *r;
    *r  = tmp;
    l++;
    r--;
  }
}