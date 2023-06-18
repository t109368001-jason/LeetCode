class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rowSetList(board.size());
    vector<unordered_set<char>> colSetList(board[0].size());
    vector<unordered_set<char>> boxSetList(9);

    for (size_t r = 0; r < board.size(); r++) {
      for (size_t c = 0; c < board[0].size(); c++) {
        if (board[r][c] == '.') {
          continue;
        }
        auto& rowSet = rowSetList[r];
        auto& colSet = colSetList[c];
        int   b      = (r / 3 * 3) + (c / 3);
        cout << b << endl;
        auto& boxSet = boxSetList[b];

        if (rowSet.find(board[r][c]) != rowSet.end()) {
          return false;
        }
        if (colSet.find(board[r][c]) != colSet.end()) {
          return false;
        }
        if (boxSet.find(board[r][c]) != boxSet.end()) {
          return false;
        }
        rowSet.insert(board[r][c]);
        colSet.insert(board[r][c]);
        boxSet.insert(board[r][c]);
      }
    }
    return true;
  }
};