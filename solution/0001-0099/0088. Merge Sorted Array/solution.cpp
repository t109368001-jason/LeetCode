class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) {
      return;
    }
    auto it1    = nums1.rend() - m;
    auto it2    = nums2.rbegin();
    auto itDest = nums1.rbegin();
    while (it1 < nums1.rend() && it2 < nums2.rend() && itDest != nums1.rend()) {
      if (*it2 > *it1) {
        swap(*itDest, *it2);
        it2++;
      } else {
        swap(*itDest, *it1);
        it1++;
      }
      itDest++;
    }
    while (it2 < nums2.rend() && itDest != nums1.rend()) {
      swap(*itDest, *it2);
      it2++;
      itDest++;
    }
  }
};