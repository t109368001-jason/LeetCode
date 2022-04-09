

int compareIntDesc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

int minimumCost(int* cost, int costSize) {
  int* end = cost + costSize;

  int* buf = calloc(costSize, sizeof(int));
  memcpy(buf, cost, costSize * sizeof(int));

  qsort(buf, costSize, sizeof(int), compareIntDesc);

  int result = 0;
  for (int i = 0; i < costSize; i++) {
    if (i % 3 == 2) { continue; }
    result += buf[i];
  }
  return result;
}