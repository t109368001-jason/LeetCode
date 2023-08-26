class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<int> dp(8);
    bool        isA = true;
    for (int i = 0; i < moves.size(); i++) {
      auto& move = moves[i];
      dp[move[0]] += isA ? 1 : -1;
      dp[move[1] + 3] += isA ? 1 : -1;
      if (move[0] == move[1]) {
        dp[6] += isA ? 1 : -1;
      }
      if ((move[0] == 0 && move[1] == 2) || (move[0] == 1 && move[1] == 1) || (move[0] == 2 && move[1] == 0)) {
        dp[7] += isA ? 1 : -1;
      }
      isA = !isA;
    }
    for (int count : dp) {
      if (count == 3) {
        return "A";
      }
      if (count == -3) {
        return "B";
      }
    }
    return moves.size() == 9 ? "Draw" : "Pending";
  }
};