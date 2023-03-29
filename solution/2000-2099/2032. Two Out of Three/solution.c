

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
  int*  buf   = calloc(100, sizeof(int));
  char* masks = calloc(100, sizeof(char));
  int   count = 0;

  int* end = nums1 + nums1Size;
  while (nums1 < end) {
    masks[nums1[0] - 1] = 1;
    nums1++;
  }
  end = nums2 + nums2Size;
  while (nums2 < end) {
    int  num  = nums2[0] - 1;
    char mask = masks[num];
    if (mask == 1) {
      masks[num] = -1;
      buf[count] = nums2[0];
      count++;
    } else if (mask == 0) {
      masks[num] = 2;
    }
    nums2++;
  }
  end = nums3 + nums3Size;
  while (nums3 < end) {
    int  num  = nums3[0] - 1;
    char mask = masks[num];
    if (mask == 1 || mask == 2) {
      masks[num] = -1;
      buf[count] = nums3[0];
      count++;
    }
    nums3++;
  }
  int* result = calloc(count, sizeof(int));
  *returnSize = count;
  for (int i = 0; i < count; i++) {
    result[i] = buf[i];
  }
  return result;
}