#include <algorithm>
#include <string>
#include <vector>

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::string res = iterable;
  res.erase(std::unique(begin(res), end(res)), end(res));
  return std::vector<char>{begin(res), end(res)};
}