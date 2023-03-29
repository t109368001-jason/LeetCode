bool hasNestedNeighbor(int i, int j, char* word, char** board, bool** passedBoard, int boardSize, int* boardColSize) {
  if (passedBoard[i][j] || board[i][j] != *word) {
    return false;
  }
  if (*(word + 1) == '\0') {
    return true;
  }
  passedBoard[i][j] = true;
  if (i > 0 && hasNestedNeighbor(i - 1, j, word + 1, board, passedBoard, boardSize, boardColSize)) {
    return true;
  }
  if (i < (boardSize - 1) && hasNestedNeighbor(i + 1, j, word + 1, board, passedBoard, boardSize, boardColSize)) {
    return true;
  }
  if (j > 0 && hasNestedNeighbor(i, j - 1, word + 1, board, passedBoard, boardSize, boardColSize)) {
    return true;
  }
  if (j < (boardColSize[i] - 1) && hasNestedNeighbor(i, j + 1, word + 1, board, passedBoard, boardSize, boardColSize)) {
    return true;
  }
  passedBoard[i][j] = false;
  return false;
}

void freeBoard(bool*** passedBoard, int boardSize, int* boardColSize) {
  for (int i = 0; i < boardSize; i++) {
    free((*passedBoard)[i]);
    (*passedBoard)[i] = NULL;
  }
  free(*passedBoard);
  *passedBoard = NULL;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
  if (!word) {
    return false;
  }
  bool** passedBoard = calloc(boardSize, sizeof(bool*));
  for (int i = 0; i < boardSize; i++) {
    passedBoard[i] = calloc(boardColSize[i], sizeof(bool));
  }
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardColSize[i]; j++) {
      // printf("start\n");
      if (hasNestedNeighbor(i, j, word, board, passedBoard, boardSize, boardColSize)) {
        freeBoard(&passedBoard, boardSize, boardColSize);
        return true;
      }
    }
  }
  freeBoard(&passedBoard, boardSize, boardColSize);
  return false;
}