void swap(int* a, int* b) {
  int tmp = *a;
  *a      = *b;
  *b      = tmp;
}

void sortColors(int* nums, int numsSize) {
  int* right = nums + numsSize - 1;

  while (nums < right) {
    if (*nums == 0) {
      nums++;
      continue;
    } else if (*right == 2) {
      right--;
      continue;
    } else if (*nums == 2) {
      swap(nums, right--);
      continue;
    } else if (*right == 0) {
      swap(nums++, right);
    } else {
      int* c = nums + 1;
      while (c < right) {
        if (*c == 0) {
          swap(nums, c);
          break;
        }
        if (*c == 2) {
          swap(c, right);
          break;
        }
        c++;
      }
      if (c >= right) {
        return;
      }
    }
  }
}
