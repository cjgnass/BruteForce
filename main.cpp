#include <iostream> 
#include <ostream>
#include "include/attacker.hpp"


template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &v) { 
  os << '[';
  std::for_each(v.cbegin(), v.cend() - 1, [&os](T x) { 
    os << x << ", ";
  });
  os << *(v.cend() - 1) << ']';
  return os;
}

int main() { 
  std::string output = bruteForce("zzzzz");
  if (output != "") { 
    std::cout << "Target found : " << output << '\n';
  }
}

