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
  char* output = new char[input.size() + 1];
  int idx = 0;
  std::for_each(input.begin(), input.end(), 
      [&output, &idx](int x){ 
        output[idx] = 'a' + x; 
        idx++;
      });
  return output;
}

std::vector<int> adder(const std::vector<int> &input1, const std::vector<int> &input2, int base) { 
  // auto invalid1 = std::find_if(input1.begin(), input1.end(), [&base](int x) { 
  //   return x >= base;
  // });
  // auto invalid2 = std::find_if(input2.begin(), input2.end(), [&base](int x) { 
  //   return x >= base;
  // });
  // if (invalid1 != input1.end() || invalid2 != input2.end()) { 
  //   std::cerr << "Invalid input or base";
  //   return {};
  // }
  std::vector<int> output(std::max(input1.size(), input2.size()));

  int carry = 0;
  int idx = output.size() - 1;
  int idx1 = input1.size() - 1;  
  int idx2 = input2.size() - 1;  

  for(;idx1 >= 0 && idx2 >= 0; idx1--, idx2--, idx--) { 
    int sum = input1[idx1] + input2[idx2] + carry;
    carry = sum / base;
    output[idx] = sum % base;
  }
  
  for(;idx1 >= 0; idx1--, idx--) { 
    int sum = input1[idx1] + carry;
    carry = sum / base;
    output[idx] = sum % base;
  }
  for(;idx2 >= 0; idx2--, idx--) { 
    int sum = input2[idx2] + carry;
    carry = sum / base;
    output[idx] = sum % base;
  }
  
  if (carry > 0) {
    output.insert(output.begin(), carry);
  }
  
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

