class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    vector<int> indices(score.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&score](int indexA, int indexB) { return score[indexA] > score[indexB]; });
    vector<string> result(score.size());

    for (int i = 0; i < indices.size(); i++) {
      int index = indices[i];
      if (i == 0) {
        result[index] = "Gold Medal";
      } else if (i == 1) {
        result[index] = "Silver Medal";
      } else if (i == 2) {
        result[index] = "Bronze Medal";
      } else {
        result[index] = to_string(i + 1);
      }
    }
    return result;
  }
};