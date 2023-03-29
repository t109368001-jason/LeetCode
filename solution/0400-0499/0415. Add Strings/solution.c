

char* addStrings(char* num1, char* num2) {
  char* end1 = num1;
  char* end2 = num2;
  while (*end1++)
    ;
  while (*end2++)
    ;
  int size1 = end1 - num1 - 1;
  int size2 = end2 - num2 - 1;
  end1 -= 2;
  end2 -= 2;
  int   sizeResult = (size1 > size2 ? size1 : size2) + 1;
  char* result     = calloc(sizeResult + 1, sizeof(char));
  memset(result, '0', sizeResult);
  char* endResult = result + sizeResult - 1;
  char  sum;
  bool  c = 0;
  while (end1 >= num1 || end2 >= num2 || c) {
    sum = 0;
    if (end1 >= num1) {
      sum += *end1 - '0';
    }
    if (end2 >= num2) {
      sum += *end2 - '0';
    }
    if (c) {
      sum++;
      c = false;
    }
    if (sum >= 10) {
      sum -= 10;
      c = true;
    }
    *endResult = sum + '0';
    end1--;
    end2--;
    endResult--;
  }
  if (result[0] == '0') {
    sizeResult--;
    char* result_ = calloc(sizeResult + 1, sizeof(char));
    memcpy(result_, result + 1, sizeResult);
    free(result);
    result = result_;
  }
  return result;
}