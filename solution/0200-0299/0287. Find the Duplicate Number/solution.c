// O(n), O(1)
int findDuplicate(int* nums, int numsSize) {
  int fast = nums[0];
  int slow = nums[0];
  do {
    fast = nums[nums[fast]];
    slow = nums[slow];
  } while (fast != slow);

  slow = nums[0];
  while (fast != slow) {
    fast = nums[fast];
    slow = nums[slow];
  }
  return fast;
}
// first success, O(n), O(n)
// int findDuplicate(int* nums, int numsSize){
//     bool* exists = calloc(numsSize - 1, sizeof(bool));
//     for(int i = 0; i < nums; i++) {
//         if(exists[nums[i]-1]) {
//             return nums[i];
//         }
//         exists[nums[i]-1] = true;
//     }
//     return -1;
// }