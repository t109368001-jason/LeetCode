int compareIntDesc(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
  int* buf = calloc(numsSize, sizeof(int));
  memcpy(buf, nums, numsSize * sizeof(int));

  qsort(buf, numsSize, sizeof(int), compareIntDesc);
  for (int i = 1; i < numsSize; i++) {
    if (buf[i - 1] == buf[i]) {
      return true;
    }
  }
  return false;
}