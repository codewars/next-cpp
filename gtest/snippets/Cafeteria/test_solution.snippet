#include <random>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <preloaded.h>
#include <solution.h>

namespace {
  TEST(Fixed_Tests, Tests) {
    {
      Coffee actual = CoffeeBuilder().set_black_coffee().with_sugar("Regular").with_milk(3.2).build();
      Coffee expected = {"Black", {{3.3}}, {{"Regular"}}};
      EXPECT_EQ(actual, expected) << expected;
    }
    
    {
      Coffee actual = CoffeeBuilder().set_antoccino_coffee().build();
      Coffee expected = {"Americano", {{0.5}}, {}};
      EXPECT_EQ(actual, expected);
    }
    
    {
      Coffee actual = CoffeeBuilder().set_cubano_coffee().build();
      Coffee expected = {"Cubano", {}, {{"Brown"}}};
      EXPECT_EQ(actual, expected);
    }
  }


  auto randint(unsigned min, unsigned max) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<unsigned> uni(min, max);
    return uni(rng);
  }
  
  std::string randstr(unsigned n) {
    static std::string base = "abcdefghijklmnopqrstuvwxyz";
    std::stringstream ss;
    while (n--) ss << base[randint(0, base.size() - 1)];
    return ss.str();
  }
  
  TEST(Random_Tests, Tests) {
    for (int i = 0; i < 100; i++) {
      Coffee c;
      CoffeeBuilder cb {};
      
      int type = randint(0, 2);
      if (type == 0) {
        c.sort = "Black";
        cb = cb.set_black_coffee();
      } else if (type == 1) {
        c.sort = "Americano";
        c.milk.push_back({0.5});
        cb = cb.set_antoccino_coffee();
      } else {
        c.sort = "Cubano";
        c.sugar.push_back({"Brown"});
        cb = cb.set_cubano_coffee();
      }
      
      for (int i = randint(0, 2); i; i--) {
        float n = randint(1, 30) / 10.0;
        c.milk.push_back({n});
        cb = cb.with_milk(n);
      }
      
      for (int i = randint(0, 2); i; i--) {
        std::string s = randstr(randint(3, 5));
        c.sugar.push_back({s});
        cb = cb.with_sugar(s);
      }
      
      EXPECT_EQ(cb.build(), c) << c;
    }
  }
}