class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> notPrime(n);
    int          count = 0;
    for (int i = 2; i < n; i++) {
      if (!notPrime[i]) {
        count++;
        if (i > 46340) {
          continue;
        }
        for (int j = i * i; j < n; j += i) {
          notPrime[j] = true;
        }
      }
    }
    return count;
  }
};