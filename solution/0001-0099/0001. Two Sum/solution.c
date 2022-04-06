/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* a   = nums;
  int* b   = a + 1;
  int* end = nums + numsSize;
  while (a < end) {
    if ((b >= end)) {
      a++;
      b = a + 1;
      continue;
    }
    if ((*a + *b) == target) {
      int* result = (int*)malloc(2 * sizeof(int));
      result[0]   = a - nums;
      result[1]   = b - nums;
      *returnSize = 2;
      return result;
    }
    b++;
  }
  return 0;
}