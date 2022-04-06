

int findKthLargest(int* nums, int numsSize, int k) {
  int* end = nums + numsSize;
  int* l   = calloc(k, sizeof(int));
  memcpy(l, nums, k * sizeof(int));
  if (numsSize > 1) {
    for (int i = 0; i < k - 1; i++) {
      bool flag = true;
      for (int j = i + 1; j < k; j++) {
        if (l[j] < l[i]) {
          int tmp = l[i];
          l[i]    = l[j];
          l[j]    = tmp;
          flag    = false;
        }
      }
      if (flag) { break; }
    }
  }
  nums += k;
  while (nums < end) {
    if (nums[0] > l[0]) {
      l[0] = nums[0];
      for (int i = 1; i < k; i++) {
        if (l[i] >= l[i - 1]) { break; }
        int tmp  = l[i - 1];
        l[i - 1] = l[i];
        l[i]     = tmp;
      }
    }
    nums++;
  }
  return l[0];
}