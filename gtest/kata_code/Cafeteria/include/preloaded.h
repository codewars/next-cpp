#ifndef CW_PRELOADED_INCLUDED
#define CW_PRELOADED_INCLUDED

#include <iostream>
#include <string>
#include <vector>

struct Milk {
  float fat;
    
  bool operator ==(const Milk &other) const {
    return fat == other.fat;
  }
};

std::ostream &operator<<(std::ostream &stream, const Milk &milk) {
  stream << "Milk(" << milk.fat << ")";
  return stream;
}



struct Sugar {
  std::string sort;
  
  bool operator ==(const Sugar &other) const {
    return sort == other.sort;
  }
};

std::ostream &operator<<(std::ostream &stream, const Sugar &sugar) {
  return (stream << "Sugar('" << sugar.sort << "')");
}



struct Coffee {
  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
  
  bool operator==(const Coffee &other) const {
    return sort == other.sort && milk == other.milk && sugar == other.sugar;
  }
};

std::ostream &operator<<(std::ostream &stream, const Coffee &coffee) {
  stream << "Coffee('" << coffee.sort << "', [";
  
  for (unsigned i = 0; i < coffee.milk.size(); i++) {
    if (i) stream << ", ";
    stream << coffee.milk[i];
  }
  
  stream << "], [";
  
  for (unsigned i = 0; i < coffee.sugar.size(); i++) {
    if (i) stream << ", ";
    stream << coffee.sugar[i];
  }
  
  stream << "])";
  
  return stream;
}

#endif // CW_PRELOADED_INCLUDED