class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[r].size(); c++) {
        if (grid[r][c] != '1') {
          continue;
        }
        brocast(grid, r, c);
        count++;
      }
    }
    return count;
  }

  void brocast(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1') {
      return;
    }
    grid[r][c] = '#';
    brocast(grid, r + 1, c);
    brocast(grid, r - 1, c);
    brocast(grid, r, c + 1);
    brocast(grid, r, c - 1);
  }
};