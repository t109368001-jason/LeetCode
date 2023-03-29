int rob(int* nums, int numsSize) {
  int* buf = calloc(numsSize, sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    buf[i]  = nums[i];
    int max = -1;
    for (int j = i - 2; j >= i - 3 && j >= 0; j--) {
      if (buf[j] > max) {
        max = buf[j];
      }
    }
    if (max > 0) {
      // printf("%d, %d, %d\n", i, max, buf[i]);
      buf[i] += max;
    }
  }
  int max = buf[0];
  for (int i = 1; i < numsSize; i++) {
    if (buf[i] > max) {
      max = buf[i];
    }
  }
  free(buf);
  return max;
}