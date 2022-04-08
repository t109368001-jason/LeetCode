

int nthUglyNumber(int n) {
  int* buf = calloc(n, sizeof(int));
  buf[0]   = 1;
  int x = 0, y = 0, z = 0;
  for (int i = 1; i < n; i++) {
    int n1 = 2 * buf[x];
    int n2 = 3 * buf[y];
    int n3 = 5 * buf[z];
    if (n1 < n2) {
      if (n1 < n3) {
        buf[i] = n1;
      } else {
        buf[i] = n3;
      }
    } else {
      if (n2 < n3) {
        buf[i] = n2;
      } else {
        buf[i] = n3;
      }
    }
    if (buf[i] == n1) { x++; }
    if (buf[i] == n2) { y++; }
    if (buf[i] == n3) { z++; }
  }
  return buf[n - 1];
}