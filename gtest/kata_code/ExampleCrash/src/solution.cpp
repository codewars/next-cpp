#include <vector>
int crashOrNot(int n) {
  return n > 0 ? 42 : ((int*)NULL)[1];
}