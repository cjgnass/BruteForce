#include "include/attacker.hpp"
#include <cstdint>

uint64_t makeBaseTen(const std::vector<int> &v, int base) { 
  uint64_t output{ 0 }; 
  uint64_t e{ 0 };
  std::for_each(v.rbegin(), v.rend(), [&base, &e, &output](int x) { 
    output += x * (std::pow(base, e++)); 
  });
  return output;
}

std::string numToString(const std::vector<int> &input) { 
  std::string output{};
  std::for_each(input.begin(), input.end(), 
      [&output](int x){ 
        output += 'a' + x; 
      });
  return output;
}

std::vector<int> adder(std::vector<int> input1, std::vector<int> input2, int base) { 
  auto invalid1 = std::find_if(input1.begin(), input1.end(), [&base](int x) { 
    return x >= base;
  });
  auto invalid2 = std::find_if(input2.begin(), input2.end(), [&base](int x) { 
    return x >= base;
  });
  if (invalid1 != input1.end() || invalid2 != input2.end()) { 
    std::cerr << "Invalid input or base";
    return {};
  }
  std::reverse(input1.begin(), input1.end());
  std::reverse(input2.begin(), input2.end());
  std::vector<int> output{};

  int carry = 0;
  int idx = 0;  
  int minSize = std::min(input1.size(), input2.size());

  for(;idx < minSize; idx++) { 
    int sum = input1[idx] + input2[idx] + carry;
    carry = sum / base;
    output.push_back(sum % base);
  }
  
  for(;idx < input1.size(); idx++) { 
    int sum = input1[idx] + carry;
    carry = sum / base;
    output.push_back(sum % base);
  }
  for(;idx < input2.size(); idx++) { 
    int sum = input2[idx] + carry;
    carry = sum / base;
    output.push_back(sum % base);
  }
  if (carry > 0) { 
    output.push_back(carry);
  }

  std::reverse(output.begin(), output.end());
  return output;
}

std::string bruteForce(std::string target) {
  uint64_t n = std::pow(26, target.size()) - 1;
  std::vector<int> v(target.size());
  if (numToString(v)==target) { 
    return numToString(v);
  }
  std::vector<int> numToAdd(target.size());
  numToAdd[target.size()-1] = 1;
  while (n > 0) { 
    v = adder(v, numToAdd, 26);
    // std::cout << numToString(v) << '\n';
    if (numToString(v)==target) { 
      return numToString(v);
    }
    n--;
  }
  std::cerr << "Target not found"; 
  return "";
}

