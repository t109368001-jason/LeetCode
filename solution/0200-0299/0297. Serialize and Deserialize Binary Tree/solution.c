/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countDigits(int num) {
  int result = 0;
  if (num < 0) {
    result++;
    num *= -1;
  }
  do {
    result++;
    num /= 10;
  } while (num > 0);
  return result;
}

void appendBuffer(char** buffer, int* maxBufferSize) {
  *maxBufferSize  = *maxBufferSize * 2 + 1;
  char* newBuffer = calloc(*maxBufferSize, sizeof(char));
  strcpy(newBuffer, *buffer);
  free(*buffer);
  *buffer = newBuffer;
}

void encodeValue(int value, char** buffer, int* bufferSize, int* maxBufferSize) {
  int digits = countDigits(value);
  while ((*maxBufferSize - *bufferSize - 1) < (digits + 2)) {
    appendBuffer(buffer, maxBufferSize);
  }
  sprintf(*buffer + *bufferSize, "%d,", value);
  *bufferSize += strlen(*buffer + *bufferSize);
}

void encodeEmptyNode(char** buffer, int* bufferSize, int* maxBufferSize) {
  while ((*maxBufferSize - *bufferSize - 1) < 3) {
    appendBuffer(buffer, maxBufferSize);
  }
  sprintf(*buffer + *bufferSize, "N,");
  *bufferSize += strlen(*buffer + *bufferSize);
}

void encodeEmptyChild(char** buffer, int* bufferSize, int* maxBufferSize) {
  while ((*maxBufferSize - *bufferSize - 1) < 3) {
    appendBuffer(buffer, maxBufferSize);
  }
  sprintf(*buffer + *bufferSize, "B,");
  *bufferSize += strlen(*buffer + *bufferSize);
}

void serializeRecursive(struct TreeNode* root, char** buffer, int* bufferSize, int* maxBufferSize) {
  encodeValue(root->val, buffer, bufferSize, maxBufferSize);
  if (!root->left && !root->right) {
    encodeEmptyChild(buffer, bufferSize, maxBufferSize);
    return;
  }
  if (root->left) {
    serializeRecursive(root->left, buffer, bufferSize, maxBufferSize);
  } else {
    encodeEmptyNode(buffer, bufferSize, maxBufferSize);
  }
  if (root->right) {
    serializeRecursive(root->right, buffer, bufferSize, maxBufferSize);
  } else {
    encodeEmptyNode(buffer, bufferSize, maxBufferSize);
  }
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
  if (!root) {
    return NULL;
  }
  char* buffer        = calloc(3, sizeof(char));
  int   bufferSize    = 0;
  int   maxBufferSize = 3;
  serializeRecursive(root, &buffer, &bufferSize, &maxBufferSize);
  return buffer;
}

void deserializeRecursive(struct TreeNode** root, char** data, int level) {
  if (**data == '\0') {
    return;
  }
  if (**data == 'N') {
    *data += 2;
    return;
  }
  *root        = calloc(1, sizeof(struct TreeNode));
  (*root)->val = atoi(*data);
  while (**data != ',' && **data != '\0') {
    (*data)++;
  }
  if (**data == '\0') {
    return;
  }
  (*data)++;
  if (**data == 'B') {
    *data += 2;
    return;
  }
  deserializeRecursive(&(*root)->left, data, level + 1);
  deserializeRecursive(&(*root)->right, data, level + 1);
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
  if (!data) {
    return NULL;
  }
  struct TreeNode* root;
  deserializeRecursive(&root, &data, 0);
  return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);