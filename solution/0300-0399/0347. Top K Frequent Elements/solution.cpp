class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int num : nums) {
      m[num]++;
    }
    vector<int>                    result;
    priority_queue<pair<int, int>> pq;
    for (auto it = m.begin(); it != m.end(); it++) {
      pq.push(make_pair(it->second, it->first));
      if (pq.size() > (int)m.size() - k) {
        result.push_back(pq.top().second);
        pq.pop();
      }
    }
    return result;
  }
};