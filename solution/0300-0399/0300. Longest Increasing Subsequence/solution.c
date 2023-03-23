int lengthOfLIS(int* nums, int numsSize) {
  int* subSeqLength = calloc(numsSize, sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    subSeqLength[i] = 1;
    int max         = -1;
    for (int j = i - 1; j >= 0; j--) {
      if (nums[j] < nums[i]) {
        if (subSeqLength[j] > max) { max = subSeqLength[j]; }
      }
    }
    if (max > 0) { subSeqLength[i] += max; }
  }
  int max = subSeqLength[0];
  for (int i = 1; i < numsSize; i++) {
    if (subSeqLength[i] > max) { max = subSeqLength[i]; }
  }
  free(subSeqLength);
  return max;
}