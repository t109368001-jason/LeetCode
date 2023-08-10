class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int  n      = nums.size();
    auto midptr = nums.begin() + n / 2;
    // [1,5,1,1,6,4]
    nth_element(nums.begin(), midptr, nums.end());
    // [1,1,1,4(mid),6,5]
    int mid = *midptr;

// Index-rewiring.
// n == 6
// 0=>1, 1=>3, 2=>5, 3=>0, 4=>2, 5=>4
// virtual index of sorted index (desc)
// [1,1,1,4(mid),6,5]
// virtual index => [1,4(mid),5,1,1,6]
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else
        j++;
    }
    // A(0) = num[1] = 1 < min = 4
    // swap(A(0), A(5)) => swap(num[1], num[4]), k = 4
    // [1,6,1,4(mid),1,5], [6,4(mid),5,1,1,1]
    // A(0) = num[1] = 6 > min = 4
    // swap(A(0), A(0)) => swap(num[1], num[1]), i = 1, j = 1
    // [1,6,1,4(mid),1,5], [6,4(mid),5,1,1,1]
    // A(1) = num[3] = 4 == mid
    // j = 2
    // A(2) = num[5] = 5 > min = 4
    // swap(A(1), A(2)) => swap(num[3], num[5]), i = 2, j = 3
    // [1,6,1,5,1,4(mid)], [6,5,4(mid),1,1,1]
    // A(3) = num[5] = 4 == mid
    // j = 4
    // A(4) = num[2] = 1 < mid = 4
    // swap(A(4), A(4)) k = 3
    // j = 4 > k = 3
  }
};