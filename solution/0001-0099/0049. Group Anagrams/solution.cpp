class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (auto& str : strs) {
      m[countingSort(str)].push_back(str);
    }
    vector<vector<string>> result;
    for (auto& [k, v] : m) {
      result.push_back(v);
    }
    return result;
  }

  string countingSort(string s) {
    int counter[26] = {0};
    for (auto& c : s) {
      counter[c - 'a']++;
    }
    string result;
    for (size_t i = 0; i < 26; i++) {
      if (counter[i] <= 0) {
        continue;
      }
      result += 'a' + i;
      result += to_string(counter[i]);
    }
    return result;
  }

  // first success
  vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    vector<vector<string>>           groupList;
    vector<unordered_map<char, int>> charSetList;

    for (auto& str : strs) {
      unordered_map<char, int> cs;
      for (auto& c : str) {
        cs[c]++;
      }
      bool find = false;
      for (size_t i = 0; i < groupList.size(); i++) {
        auto& charSet = charSetList[i];
        if (cs.size() != charSet.size()) {
          continue;
        }
        find = true;
        for (auto& [c, count] : cs) {
          if (charSet.find(c) == charSet.end() || charSet[c] != count) {
            find = false;
            break;
          }
        }
        if (find) {
          groupList[i].push_back(str);
          break;
        }
      }
      if (!find) {
        groupList.push_back({str});
        charSetList.push_back(cs);
      }
    }
    return groupList;
  }
};