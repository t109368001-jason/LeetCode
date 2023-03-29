/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarySearch(int target, int* nums, int l, int r) {
  if (r == l) {
    return -1;
  }
  if (r - l < 2) {
    if (nums[l] == target) {
      return l;
    }
    if (nums[r] == target) {
      return r;
    }
    return -1;
  }
  int p = (l + r) / 2;
  if (nums[p] == target) {
    return p;
  }
  if (nums[p] < target) {
    return binarySearch(target, nums, p, r);
  } else {
    return binarySearch(target, nums, l, p);
  }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  int* result = calloc(2, sizeof(int));
  *returnSize = 2;
  result[0]   = -1;
  result[1]   = -1;
  if (numsSize == 0) {
    return result;
  }
  if (numsSize == 1) {
    if (nums[0] == target) {
      result[0] = 0;
      result[1] = 0;
    }
    return result;
  }
  result[0] = result[1] = binarySearch(target, nums, 0, numsSize - 1);
  if (result[0] != -1) {
    while (result[0] > 0 && nums[result[0] - 1] == target) {
      result[0]--;
    }
    while (result[1] < numsSize - 1 && nums[result[1] + 1] == target) {
      result[1]++;
    }
  }
  return result;
}