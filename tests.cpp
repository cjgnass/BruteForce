#include <cstdint>
#include <gtest/gtest.h>
#include "attacker.hpp"
#include "include/attacker.hpp"

TEST(NumToString, Test1) {
  std::string o = numToString(std::vector<int>{0, 1, 2});
  std::string t{"abc"};
  EXPECT_EQ(o, t);
}

TEST(NumToString, Test2) {
  std::string o = numToString(std::vector<int>{25, 24, 23});
  std::string t{"zyx"};
  EXPECT_EQ(o, t);
}

TEST(MakeBaseTen, Test1) {
  uint64_t o{ makeBaseTen(std::vector<int>{1, 1}, 2)};
  uint64_t t { 3 };
  EXPECT_EQ(o, t);
}

TEST(MakeBaseTen, Test2) {
  uint64_t o{ makeBaseTen(std::vector<int>{1, 23}, 26)};
  uint64_t t { 49 };
  EXPECT_EQ(o, t);
}

TEST(MakeBaseTen, Test3) {
  int o = makeBaseTen(std::vector<int>{7, 0, 11, 0, 0, 33}, 26);
  int t = 83363001;
  EXPECT_EQ(o, t);
}

TEST(Adder, Test1) { 
  std::vector<int> i1 {1, 1, 1};
  std::vector<int> i2 {1, 1, 1};
  std::vector<int> o = adder(i1, i2, 2);
  std::vector<int> t  {1, 1, 1, 0};
  EXPECT_EQ(o, t);

}

TEST(Adder, Test2) { 
  std::vector<int> i1 {1};
  std::vector<int> i2 {25};
  std::vector<int> o = adder(i1, i2, 26);
  std::vector<int> t  {1, 0};
  EXPECT_EQ(o, t);
}

TEST(AdderAndMakeBaseTen, Test1) { 
  std::vector<int> i1 {25};
  std::vector<int> i2 {25};
  std::vector<int> outSum = adder(i1, i2, 26);
  std::vector<int> truthSum {1, 24};
  uint32_t o = makeBaseTen(outSum, 26);
  uint32_t t = makeBaseTen(truthSum , 26);
  EXPECT_EQ(o, t);
}
