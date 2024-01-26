#include <string>
#include <vector>

#include <preloaded.h>

class CoffeeBuilder {
  public:
    std::string sort;
    std::vector<Milk> milk;
    std::vector<Sugar> sugar;
  
    CoffeeBuilder set_black_coffee() {
      sort = "Black";
      return *this;
    }
  
    CoffeeBuilder set_cubano_coffee() {
      sort = "Cubano";
      sugar.push_back({"Brown"});
      return *this;
    }
  
    CoffeeBuilder set_antoccino_coffee() {
      sort = "Americano";
      milk.push_back({0.5});
      return *this;
    }
  
    CoffeeBuilder with_milk(float n) {
      milk.push_back({n});
      return *this;
    }
  
    CoffeeBuilder with_sugar(const std::string &s) {
      sugar.push_back({s});
      return *this;
    }
  
    Coffee build() {
      return {sort, milk, sugar};
    }
};