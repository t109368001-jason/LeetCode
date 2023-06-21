class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool col0 = false;
    for (int row = 0; row < matrix.size(); row++) {
      if (matrix[row][0] == 0) {
        col0 = true;
      }
      for (int col = 1; col < matrix[row].size(); col++) {
        if (matrix[row][col] == 0) {
          matrix[row][0] = 0;
          matrix[0][col] = 0;
        }
      }
    }
    for (int row = matrix.size() - 1; row >= 0; row--) {
      for (int col = 1; col < matrix[row].size(); col++) {
        if (matrix[row][0] == 0 || matrix[0][col] == 0) {
          matrix[row][col] = 0;
        }
      }
      if (col0) {
        matrix[row][0] = 0;
      }
    }
  }
  // first success O(n^2), O(n)
  void setZeroes1(vector<vector<int>>& matrix) {
    vector<bool> rowMask(matrix.size());
    vector<bool> colMask(matrix.size());
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = 0; col < matrix[row].size(); col++) {
        if (matrix[row][col] == 0) {
          rowMask[row] = true;
          colMask[col] = true;
        }
      }
    }
    for (int row = 0; row < matrix.size(); row++) {
      if (!rowMask[row]) {
        continue;
      }
      for (int col = 0; col < matrix[row].size(); col++) {
        matrix[row][col] = 0;
      }
    }
    for (int col = 0; col < matrix[0].size(); col++) {
      if (!colMask[col]) {
        continue;
      }
      for (int row = 0; row < matrix.size(); row++) {
        matrix[row][col] = 0;
      }
    }
  }
};