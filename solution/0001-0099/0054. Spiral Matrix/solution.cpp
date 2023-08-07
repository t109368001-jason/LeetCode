class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int         m = matrix.size();
    int         n = m ? matrix[0].size() : 0;
    int         u = 0;
    int         d = m - 1;
    int         l = 0;
    int         r = n - 1;
    int         p = 0;
    vector<int> result(m * n);
    while (u <= d && l <= r) {
      for (int col = l; col <= r; col++) {
        result[p++] = matrix[u][col];
      }
      if (++u > d) {
        break;
      }
      for (int row = u; row <= d; row++) {
        result[p++] = matrix[row][r];
      }
      if (--r < l) {
        break;
      }
      for (int col = r; col >= l; col--) {
        result[p++] = matrix[d][col];
      }
      if (--d < u) {
        break;
      }
      for (int row = d; row >= u; row--) {
        result[p++] = matrix[row][l];
      }
      if (l++ > r) {
        break;
      }
    }
    return result;
  }
};