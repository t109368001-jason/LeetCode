

int maxArea(int* height, int heightSize) {
  int* end = height + heightSize - 1;
  int  max = 0;
  while (height < end) {
    int num = end - height;
    if (*height > *end) {
      num *= *end;
      end--;
    } else {
      num *= *height;
      height++;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}