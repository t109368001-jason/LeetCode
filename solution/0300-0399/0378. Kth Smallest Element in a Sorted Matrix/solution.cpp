class Solution {
 public:
  int m, n;
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    m = matrix.size(), n = matrix[0].size();
    int left  = matrix[0][0];
    int right = matrix[m - 1][n - 1];
    int ans   = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (countLessOrEqual(matrix, mid) >= k) {
        ans   = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
  int countLessOrEqual(vector<vector<int>>& matrix, int x) {
    int cnt = 0;
    int c   = n - 1;
    for (int r = 0; r < m; ++r) {
      while (c >= 0 && matrix[r][c] > x) {
        --c;
      }
      cnt += (c + 1);
    }
    return cnt;
  }
};