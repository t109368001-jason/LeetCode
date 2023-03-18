/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void _qsort(int* nums, int first, int last) {
  int i, j, pivot, temp;
  if (first < last) {
    pivot = first;
    i     = first;
    j     = last;
    while (i < j) {
      while (nums[i] <= nums[pivot] && i < last) i++;
      while (nums[j] > nums[pivot]) j--;
      if (i < j) {
        temp    = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    temp        = nums[pivot];
    nums[pivot] = nums[j];
    nums[j]     = temp;
    _qsort(nums, first, j - 1);
    _qsort(nums, j + 1, last);
  }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int* sortedNums = calloc(numsSize, sizeof(int));
  for (int i = 0; i < numsSize; i++) { sortedNums[i] = nums[i]; }
  _qsort(sortedNums, 0, numsSize - 1);

  int   resultMaxSize = numsSize;
  int** result        = calloc(resultMaxSize, sizeof(int*));
  *returnSize         = 0;
  for (int i = 0; i < numsSize; i++) {
    if (i != 0 && sortedNums[i - 1] == sortedNums[i]) { continue; }
    int  lastK = numsSize - 1;
    int* l     = sortedNums + i + 1;
    int* r     = sortedNums + numsSize - 1;
    while (l < r) {
      int sum = sortedNums[i] + *l + *r;
      if (sum > 0) {
        r--;
        continue;
      }
      if (sum < 0) {
        l++;
        continue;
      }
      if ((*returnSize + 1) >= resultMaxSize) {
        resultMaxSize *= 2;
        int** newResult = calloc(resultMaxSize, sizeof(int*));
        for (int ii = 0; ii < *returnSize; ii++) { newResult[ii] = result[ii]; }
        free(result);
        result = newResult;
      }
      result[*returnSize]    = calloc(3, sizeof(int));
      result[*returnSize][0] = sortedNums[i];
      result[*returnSize][1] = *l;
      result[*returnSize][2] = *r;
      (*returnSize)++;
      while (l < r) {
        if (*(l + 1) == *l) {
          l++;
          continue;
        }
        if (*(r - 1) == *r) {
          r--;
          continue;
        }
        break;
      }
      l++;
      r--;
    }
  }
  int** newResult    = calloc(*returnSize, sizeof(int*));
  *returnColumnSizes = calloc(*returnSize, sizeof(int));
  for (int ii = 0; ii < *returnSize; ii++) {
    newResult[ii]            = result[ii];
    (*returnColumnSizes)[ii] = 3;
  }
  free(result);
  result = newResult;
  return result;
}