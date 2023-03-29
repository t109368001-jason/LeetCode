// too slow

int numOfSubarrays(int* arr, int arrSize) {
  int  result = 0;
  int* start  = arr - 1;
  int* end    = arr + arrSize;
  int* c      = arr;
  int* l;
  int* r;
  // int* nextC = 0;
  while (c != end) {
    if (*c & 1) {
      l = c - 1;
      r = c + 1;
      while (l != start && !(*l & 1)) {
        l--;
      }
      int  m    = (c - l);
      bool flag = true;
      int  n    = 1;
      while (r != end) {
        if (*r++ & 1) {
          flag = !flag;
        }
        if (flag) {
          n++;
        }
        // r++;
      }
      result += n * m;
    }
    c++;
  }
  return result;
}
