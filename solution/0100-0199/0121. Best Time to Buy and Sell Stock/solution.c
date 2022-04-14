

int maxProfit(int* prices, int pricesSize) {
  int min    = INT_MAX;
  int result = 0;
  for (int i = 0; i < pricesSize; i++) {
    if (prices[i] < min) {
      min = prices[i];
      continue;
    }
    int num = prices[i] - min;
    if (num > result) { result = num; }
  }
  return result;
}