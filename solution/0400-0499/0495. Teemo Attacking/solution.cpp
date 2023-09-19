
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int count = 0;
    for (int i = 0; i < timeSeries.size() - 1; i++) {
      count += min(duration, timeSeries[i + 1] - timeSeries[i]);
    }
    count += duration;
    return count;
  }
};