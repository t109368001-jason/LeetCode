class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) { gameOfLifeRecursive(0, board); }

  void gameOfLifeRecursive(int currentRow, vector<vector<int>>& board) {
    if (currentRow >= board.size()) {
      return;
    }
    int         rows = board.size();
    int         cols = board[currentRow].size();
    vector<int> result(board[currentRow].size());
    for (int col = 0; col < board[currentRow].size(); col++) {
      int liveCount = 0;
      for (int i = max(0, currentRow - 1); i < min(rows, currentRow + 2); i++) {
        for (int j = max(0, col - 1); j < min(cols, col + 2); j++) {
          if (i == currentRow && j == col) {
            continue;
          }
          if (board[i][j] == 1) {
            liveCount++;
          }
        }
      }
      if (board[currentRow][col] == 0) {
        result[col] = liveCount == 3;
      } else {
        result[col] = 2 <= liveCount && liveCount <= 3;
      }
    }
    gameOfLifeRecursive(currentRow + 1, board);
    board[currentRow] = result;
  }
};