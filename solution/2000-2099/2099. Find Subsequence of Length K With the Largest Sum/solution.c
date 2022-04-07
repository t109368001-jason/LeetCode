

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void smallestToFirst(int* buf, int** bufAddr, int k) {
  int index = 0;
  for (int i = 1; i < k; i++) {
    if (buf[i] < buf[index]) { index = i; }
  }
  if (index != 0) {
    int tmp        = buf[0];
    buf[0]         = buf[index];
    buf[index]     = tmp;
    int* tmpAddr   = bufAddr[0];
    bufAddr[0]     = bufAddr[index];
    bufAddr[index] = tmpAddr;
  }
}

void sortAddr(int* buf, int** bufAddr, int k) {
  for (int i = k; i > 0; i--) {
    bool flag = true;
    for (int j = 1; j < i; j++) {
      if (bufAddr[j - 1] > bufAddr[j]) {
        int tmp        = buf[j - 1];
        buf[j - 1]     = buf[j];
        buf[j]         = tmp;
        int* tmpAddr   = bufAddr[j - 1];
        bufAddr[j - 1] = bufAddr[j];
        bufAddr[j]     = tmpAddr;
        flag           = false;
      }
    }
    if (flag) { break; }
  }
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
  int*  end     = nums + numsSize;
  int*  buf     = calloc(k, sizeof(int));
  int** bufAddr = calloc(k, sizeof(int*));
  for (int i = 0; i < k; i++) {
    buf[i]     = nums[0];
    bufAddr[i] = nums;
    nums++;
  }
  smallestToFirst(buf, bufAddr, k);
  *returnSize = k;

  while (nums < end) {
    if (nums[0] > buf[0]) {
      buf[0]     = nums[0];
      bufAddr[0] = nums;
      smallestToFirst(buf, bufAddr, k);
    }
    nums++;
  }
  sortAddr(buf, bufAddr, k);
  free(bufAddr);
  return buf;
}