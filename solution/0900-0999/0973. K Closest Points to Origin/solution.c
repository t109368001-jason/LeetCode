
int pointDistance2D(int* p) { return p[0] * p[0] + p[1] * p[1]; }

int comparePointDistance2DAsc(const void* a, const void* b) {
  return (pointDistance2D(*(int**)a) - pointDistance2D(*(int**)b));
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
  qsort(points, pointsSize, sizeof(int*), comparePointDistance2DAsc);

  int** result       = calloc(k, sizeof(int*));
  *returnSize        = k;
  *returnColumnSizes = calloc(k, sizeof(int));
  for (int i = 0; i < k; i++) {
    result[i]               = calloc(2, sizeof(int));
    result[i][0]            = points[i][0];
    result[i][1]            = points[i][1];
    (*returnColumnSizes)[i] = 2;
  }
  return result;
}