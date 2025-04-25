#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
std::string to_string(const std::vector<T>& nums) {
  std::ostringstream oss;
  oss << "[";
  bool first = true;
  for (auto& num : nums) {
    if (!first) {
      oss << " ,";
    }
    oss << num;
    first = false;
  }
  oss << "]" << std::endl;
  return oss.str();
}

int main() {
  
  return 0;
}