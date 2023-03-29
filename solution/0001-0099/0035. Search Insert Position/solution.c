

int searchInsert(int* nums, int numsSize, int target) {
  int* l = nums;
  int* r = nums + numsSize - 1;
  int* c = l + (r - l) / 2;
  if (nums[0] > target) {
    return 0;
  }
  if (nums[numsSize - 1] < target) {
    return numsSize;
  }
  while (l != c && r != c) {
    printf("%d %d %d\n", l, c, r);
    if (*c == target) {
      return c - nums;
    } else if (*c > target) {
      r = c;
      c = l + (r - l) / 2;
    } else {
      l = c;
      c = l + (r - l) / 2;
    }
  }
  if (*c < target) {
    return c - nums + 1;
  }
  return c - nums;
}