#include <iostream> 
#include "include/attacker.hpp"


int main() { 
  std::string output = bruteForce("zzzz");
  if (output != "") { 
    std::cout << "Target found : " << output << '\n';
  }
}

