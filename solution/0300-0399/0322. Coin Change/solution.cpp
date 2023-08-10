class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (oddAmountEvenCoins(coins, amount)) return -1;

    sort(coins.begin(), coins.end());
    int least = amount / coins[coins.size() - 1];
    int most  = amount / coins[0];

    for (int i = least; i <= most; i++) {
      if (check(coins, coins.size() - 1, i, amount)) return i;
    }

    return -1;
  }

  bool check(vector<int>& coins, int index, int count, double target) {
    double sum = (double)coins[index] * count;
    if (sum == target) return true;
    if (sum < target) return false;
    if (index == 0) return false;

    for (int i = 0; i <= count; i++) {
      double remain = target - coins[index] * i;
      if (remain < 0) break;
      if (check(coins, index - 1, count - i, remain)) return true;
    }
    return false;
  }

  // DP 11%/96%
  int coinChange1(vector<int>& coins, int amount) {
    if (oddAmountEvenCoins(coins, amount)) {
      return -1;
    }
    sort(coins.begin(), coins.end());
    int dp[++amount];
    dp[0] = 0;
    for (int i = 1; i < amount; i++) {
      dp[i] = INT_MAX;
      for (int c : coins) {
        if (i < c) {
          break;
        }
        if (dp[i - c] != INT_MAX) {
          dp[i] = min(dp[i], 1 + dp[i - c]);
        }
      }
      cout << dp[i] << ", ";
    }

    return dp[--amount] == INT_MAX ? -1 : dp[amount];
  }

  bool oddAmountEvenCoins(vector<int>& coins, int amount) {
    if (amount % 2 == 1) {
      int i = 0;
      for (int i = 0; i < coins.size(); i++)
        if (coins[i] % 2 != 0) return false;
      return true;
    }
    return false;
  }
};