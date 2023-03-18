void rotate(int* nums, int numsSize, int k) {
  k = k % numsSize;
  if (k == 0) { return; }
  int i = 0;
  int j = i + k;
  for (int ii = 0; ii < numsSize - 1; ii++) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    j       = (j + k) % numsSize;
    if (j == i) {
      ii++;
      i = (i + 1) % numsSize;
      j = (i + k) % numsSize;
    }
  }
}