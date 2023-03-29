int compareIntAsc(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int compareIntDesc(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int pointDistance2D(int* p) {
  return p[0] * p[0] + p[1] * p[1];
}

int comparePointDistance2DAsc(const void* a, const void* b) {
  return (pointDistance2D(*(int**)a) - pointDistance2D(*(int**)b));
}