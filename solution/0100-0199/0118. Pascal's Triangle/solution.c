/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
  int** result       = calloc(numRows, sizeof(int*));
  *returnSize        = numRows;
  *returnColumnSizes = calloc(numRows, sizeof(int*));
  for (int i = 0; i < numRows; i++) {
    int cols                = i + 1;
    (*returnColumnSizes)[i] = cols;
    result[i]               = calloc(cols, sizeof(int));
    for (int j = 0; j < cols; j++) {
      result[i][j] = 1;
    }
    for (int j = 1; j < cols - 1; j++) {
      result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    }
  }
  return result;
}