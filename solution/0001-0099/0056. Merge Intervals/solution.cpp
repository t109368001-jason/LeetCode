class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0) {
      return result;
    }
    sort(intervals.begin(), intervals.end());
    auto it = intervals.begin();
    result.push_back(*it);
    it++;
    for (; it != intervals.end(); it++) {
      auto& back = result.back();
      if (back[1] >= (*it)[0]) {
        back[1] = max(back[1], (*it)[1]);
      } else {
        result.push_back(*it);
      }
    }
    return result;
  }
};