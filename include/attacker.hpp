#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdint>

uint64_t makeBaseTen(const std::vector<int> &v, int base);

std::vector<int> adder(std::vector<int> input1, std::vector<int> input2, int base);

std::string numToString(const std::vector<int> &input);

std::string bruteForce(std::string target);

