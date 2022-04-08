

int matrixScore(int** grid, int gridSize, int* gridColSize) {
  for (int row = 0; row < gridSize; row++) {
    if (**(grid + row) == 0) {
      for (int col = 0; col < *gridColSize; col++) { *(*(grid + row) + col) = !(*(*(grid + row) + col)); }
    }
  }
  int threshold = gridSize / 2;
  int zeroCount;
  for (int col = 0; col < *gridColSize; col++) {
    zeroCount = 0;
    for (int row = 0; row < gridSize; row++) {
      if (!(*(*(grid + row) + col))) { zeroCount++; }
    }
    if (zeroCount > threshold) {
      for (int row = 0; row < gridSize; row++) { *(*(grid + row) + col) = !(*(*(grid + row) + col)); }
    }
  }
  int result = 0;
  for (int row = 0; row < gridSize; row++) {
    int score = 0;
    for (int col = 0; col < *gridColSize; col++) {
      score = score << 1;
      score += *(*(grid + row) + col);
    }
    result += score;
  }

  return result;
}