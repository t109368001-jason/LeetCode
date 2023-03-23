bool increasingTriplet(int* nums, int numsSize) {
  if (numsSize < 3) return false;

  int left = INT_MAX;
  int mid  = INT_MAX;

  for (int i = 0; i < numsSize; i++) {
    // if nums[i] is greater than mid means nums[i] is also greater than left means two elements before index i is less
    // than nums[i] and that are left and mid. we find that it sataisfy the condition of triplet so we return true.
    if (nums[i] > mid) return true;

    // if nums[i] is greater than left and less than mid then it is clear that we find b in a < b < c because it is
    // quite possible that c can be INT_MAX.
    else if (nums[i] > left && nums[i] < mid)
      mid = nums[i];

    // if nums[i] less than left then we update the value of left to nums[i] because we find a smaller element than it's
    // previous value.
    else if (nums[i] < left)
      left = nums[i];
  }

  // when we traversed whole array means there is no triplet so we return false.
  return false;
}

// first success
// bool increasingTriplet(int* nums, int numsSize){
//     int minI = INT_MAX;
//     int minJ = INT_MAX;
//     for(int i = 0; i < numsSize - 2; i++) {
//         if(nums[i] >= minI) {
//             continue;
//         }
//         if(i != 0 && nums[i-1] == nums[i]) {
//             continue;
//         }
//         for(int j = i + 1; j < numsSize - 1; j++) {
//             if(nums[j] >= minJ) {
//                 continue;
//             }
//             if(nums[i] >= nums[j]) {
//                 continue;
//             }
//             if(nums[j-1] == nums[j]) {
//                 continue;
//             }
//             for(int k =  j + 1; k < numsSize; k++) {
//                 if(nums[j] < nums[k]) {
//                     return true;
//                 }
//             }
//             if(nums[j] < minJ) {
//                 minJ = nums[j];
//             }
//         }
//         if(nums[i] < minI) {
//             minI = nums[i];
//             minJ = INT_MAX;
//         }
//     }
//     return false;
// }
