class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> counter;
    for (int i = lowLimit; i <= highLimit; i++) {
      int tmp = i;
      int sum = 0;
      while (tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
      }
      counter[sum]++;
    }
    return max_element(counter.begin(), counter.end(), [](auto& a, auto& b) { return a.second < b.second; })->second;
  }
};