bool canJump(int* nums, int numsSize) {
  int i = 0;
  for (int maxReach = 0; i < numsSize && i <= maxReach; ++i) {
    int reach = i + nums[i];
    maxReach  = reach > maxReach ? reach : maxReach;
  }
  return i == numsSize;
}