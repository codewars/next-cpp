#include <algorithm>
#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> res = iterable;
  res.erase(std::unique(begin(res), end(res)), end(res));
  return res;
}
std::vector<char> uniqueInOrder(const std::string& iterable);
