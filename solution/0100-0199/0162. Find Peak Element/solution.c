int findPeakElementRecursive(int* nums, int l, int r) {
  if (r == l) {
    return l;
  }
  if (r - l == 1) {
    return nums[r] > nums[l] ? r : l;
  }
  int p = (l + r) / 2;
  if (nums[p] < nums[p + 1]) {
    return findPeakElementRecursive(nums, p, r);
  } else {
    return findPeakElementRecursive(nums, l, p);
  }
}

int findPeakElement(int* nums, int numsSize) {
  if (numsSize == 1) {
    return 0;
  }
  if (numsSize == 2) {
    return nums[0] > nums[1] ? 0 : 1;
  }
  return findPeakElementRecursive(nums, 0, numsSize - 1);
}