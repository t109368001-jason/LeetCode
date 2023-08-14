class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int                    n = nums.size();
    vector<pair<int, int>> numIndexPairs;
    numIndexPairs.reserve(n);
    for (int i = 0; i < n; ++i) {
      numIndexPairs.emplace_back(nums[i], i);
    }
    vector<int> count(n, 0);
    sortCount(numIndexPairs.begin(), numIndexPairs.end(), count);
    return count;
  }

#define iterator vector<pair<int, int>>::iterator

  void sortCount(iterator l, iterator r, vector<int>& count) {
    if (r - l <= 1) return;
    iterator m = l + (r - l) / 2;
    sortCount(l, m, count);
    sortCount(m, r, count);
    for (iterator i = l, j = m; i < m; i++) {
      // find next j larger then i
      while (j < r && i->first > j->first) {
        j++;
      }
      auto smallerCountInRight = j - m;
      count[i->second] += smallerCountInRight;
    }
    inplace_merge(l, m, r);
  }
};