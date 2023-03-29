

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
  int* sandwichesEnd = sandwiches + sandwichesSize;
  int* buf           = calloc(studentsSize, sizeof(int));
  memcpy(buf, students, sizeof(int) * studentsSize);
  int remain    = studentsSize;
  int skipCount = 0;
  while (skipCount < remain && sandwiches < sandwichesEnd) {
    if (buf[0] == sandwiches[0]) {
      remain--;
      skipCount = 0;
      sandwiches++;
      for (int i = 0; i < remain; i++) {
        buf[i] = buf[i + 1];
      }
    } else {
      int tmp = buf[0];
      for (int i = 0; i < remain - 1; i++) {
        buf[i] = buf[i + 1];
      }
      buf[remain - 1] = tmp;
      skipCount++;
    }
  }
  return remain;
}