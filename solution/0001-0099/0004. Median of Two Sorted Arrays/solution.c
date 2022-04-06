double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int* m1     = nums1;
  int* n1     = nums1 + nums1Size - 1;
  int* m2     = nums2;
  int* n2     = nums2 + nums2Size - 1;
  int  remain = nums1Size + nums2Size;
  if (m1 > n1) {
    m1 = 0;
    n1 = 0;
  }
  if (m2 > n2) {
    m2 = 0;
    n2 = 0;
  }

  while (remain > 2) {
    if (m1 == 0) {
      m2++;
    } else if (m2 == 0) {
      m1++;
    } else if (*m1 < *m2) {
      m1++;
    } else {
      m2++;
    }
    if (n1 == 0) {
      n2--;
    } else if (n2 == 0) {
      n1--;
    } else if (*n1 > *n2) {
      n1--;
    } else {
      n2--;
    }
    if (m1 > n1) {
      m1 = 0;
      n1 = 0;
    }
    if (m2 > n2) {
      m2 = 0;
      n2 = 0;
    }
    remain = 0;
    if (m1 != 0) { remain += n1 - m1 + 1; }
    if (m2 != 0) { remain += n2 - m2 + 1; }
  }
  if (m1 == 0) {
    return ((double)(*m2 + *n2)) / 2;
  } else if (m2 == 0) {
    return ((double)(*m1 + *n1)) / 2;
  } else {
    return ((double)(*m1 + *m2)) / 2;
  }
  return 0;
}