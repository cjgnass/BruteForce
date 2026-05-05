#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <thread>

uint64_t makeBaseTen(const std::vector<int> &v, int base);

std::vector<int> makeBaseN(uint64_t num, int base);

std::vector<int> adder(const std::vector<int> &input1, const std::vector<int> &input2, int base);

std::string numToString(const std::vector<int> &input);

void bruteForceWork(std::string &output, const std::string &target, uint64_t start, uint64_t stop);
std::string bruteForce(const std::string &target);

