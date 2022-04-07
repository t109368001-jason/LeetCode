

int removeDuplicates(int* nums, int numsSize) {
  int* end = nums + numsSize;
  int* l   = nums;
  int* r   = nums + 1;
  while (r < end) {
    if (*r != *l) {
      l++;
      *l = *r;
    }
    r++;
  }
  return l - nums + 1;
}