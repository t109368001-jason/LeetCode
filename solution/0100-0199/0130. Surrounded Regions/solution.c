void markA(int i, int j, char** board, int boardSize, int* boardColSize) {
  if (board[i][j] != 'O') { return; }
  board[i][j] = 'A';
  if (i > 0) { markA(i - 1, j, board, boardSize, boardColSize); }
  if (i < (boardSize - 1)) { markA(i + 1, j, board, boardSize, boardColSize); }
  if (j > 0) { markA(i, j - 1, board, boardSize, boardColSize); }
  if (j < (boardColSize[i] - 1)) { markA(i, j + 1, board, boardSize, boardColSize); }
}

void solve(char** board, int boardSize, int* boardColSize) {
  if (boardSize <= 1 || boardColSize[0] <= 1) { return; }
  for (int i = 0; i < boardSize; i++) {
    markA(i, 0, board, boardSize, boardColSize);
    markA(i, boardColSize[i] - 1, board, boardSize, boardColSize);
  }
  for (int j = 0; j < boardColSize[0]; j++) {
    markA(0, j, board, boardSize, boardColSize);
    markA(boardSize - 1, j, board, boardSize, boardColSize);
  }
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardColSize[i]; j++) {
      if (board[i][j] == 'O') { board[i][j] = 'X'; }
      if (board[i][j] == 'A') { board[i][j] = 'O'; }
    }
  }
}