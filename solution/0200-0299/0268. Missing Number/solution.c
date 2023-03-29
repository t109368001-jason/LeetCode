int missingNumber(int* nums, int numsSize) {
  int sum = (numsSize * (numsSize + 1)) / 2;
  for (int i = 0; i < numsSize; i++) {
    sum -= nums[i];
  }
  return sum;
}
// first success O(n), O(n)
// int missingNumber(int* nums, int numsSize){
//     bool* find = calloc(numsSize + 1, sizeof(bool));
//     for(int i = 0; i < numsSize; i++) {
//         find[nums[i]] = true;
//     }
//     for(int i = 0; i < numsSize + 1; i++) {
//         if(!find[i]) {
//             return i;
//         }
//     }
//     return 0;
// }