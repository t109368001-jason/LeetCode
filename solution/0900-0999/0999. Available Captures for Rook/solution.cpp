class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    if (board.empty()) {
      return 0;
    }
    int            n   = board.size();
    int            m   = board[0].size();
    pair<int, int> loc = findR(n, m, board);
    if (loc.first == -1) {
      return 0;
    }
    int                         result     = 0;
    std::vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto& d : directions) {
      for (int r = loc.first + d.first, c = loc.second + d.second; 0 <= r && r < n && 0 <= c && c < m;
           r += d.first, c += d.second) {
        if (board[r][c] == 'p') {
          result++;
        }
        if (board[r][c] != '.') {
          break;
        }
      }
    }
    return result;
  }

  pair<int, int> findR(int n, int m, vector<vector<char>>& board) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (board[r][c] == 'R') {
          return {r, c};
        }
      }
    }
    return {-1, -1};
  }
};