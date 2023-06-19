class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) { rotate(0, matrix.size(), matrix); }

  void rotate(vector<vector<int>>& matrix, bool clockwise) {
    if (clockwise) {
      reverse(matrix.begin(), matrix.end());
    } else {
      for (auto vi : matrix) reverse(vi.begin(), vi.end());
    }
    transpose(matrix);
  }

  void transpose(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i + 1; j < matrix[i].size(); ++j) swap(matrix[i][j], matrix[j][i]);
    }
  }

  // first success
  void rotate(int offset, int length, vector<vector<int>>& matrix) {
    for (int i = 0; i < length - 1; i++) {
      cout << matrix[offset][offset + i] << ", " << matrix[offset + i][offset + length - 1] << endl;
      swap(matrix[offset][offset + i], matrix[offset + i][offset + length - 1]);
      cout << matrix[offset][offset + i] << ", " << matrix[offset + length - 1][offset + length - 1 - i] << endl;
      swap(matrix[offset][offset + i], matrix[offset + length - 1][offset + length - 1 - i]);
      cout << matrix[offset][offset + i] << ", " << matrix[offset + length - 1 - i][offset] << endl;
      swap(matrix[offset][offset + i], matrix[offset + length - 1 - i][offset]);
    }
    if (length > 3) {
      rotate(offset + 1, length - 2, matrix);
    }
  }
};