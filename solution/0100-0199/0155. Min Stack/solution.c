

typedef struct MinStack_ {
  int               val;
  struct MinStack_* next;
} MinStack;

MinStack* minStackCreate() { return calloc(1, sizeof(MinStack)); }

void minStackPush(MinStack* obj, int val) {
  if (!obj->next || val < obj->val) { obj->val = val; }
  MinStack* tmp = calloc(1, sizeof(MinStack));
  tmp->val      = val;
  tmp->next     = obj->next;
  obj->next     = tmp;
}

void minStackPop(MinStack* obj) {
  if (!obj->next) { return; }
  MinStack* tmp = obj->next;
  obj->next     = obj->next->next;
  if (obj->next && obj->val == tmp->val) {
    MinStack* min = obj->next;
    obj->val      = min->val;
    while (min) {
      if (min->val < obj->val) { obj->val = min->val; }
      min = min->next;
    }
  }
  free(tmp);
}

int minStackTop(MinStack* obj) {
  if (!obj->next) { return 0; }
  return obj->next->val;
}

int minStackGetMin(MinStack* obj) { return obj->val; }

void minStackFree(MinStack* obj) {
  if (obj->next) { minStackFree(obj->next); }
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/