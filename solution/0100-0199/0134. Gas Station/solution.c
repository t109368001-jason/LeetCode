int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
  int minSum    = gas[0] - cost[0];
  int minIndedx = 0;
  int sum       = minSum;
  for (int i = 1; i < gasSize; i++) {
    sum += gas[i];
    sum -= cost[i];
    if (sum < minSum) {
      minSum    = sum;
      minIndedx = i;
    }
  }
  return sum >= 0 ? ((minIndedx + 1) % gasSize) : -1;
}