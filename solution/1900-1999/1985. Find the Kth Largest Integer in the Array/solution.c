int compareNumStrDesc(void* a, void* b) {
  char* sa = *((char**)a);
  char* sb = *((char**)b);
  int   la = strlen(sa);
  int   lb = strlen(sb);
  if (la != lb) {
    return (lb - la);
  }
  while (*sa && &sb) {
    if (*sa != *sb) {
      return (*sb - *sa);
    }
    sa++;
    sb++;
  }
  return 0;
}

char* kthLargestNumber(char** nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(char*), compareNumStrDesc);
  return strdup(nums[k - 1]);
  ;
}