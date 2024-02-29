#include <iostream>
#include <string>
#include <vector>
int main() {
  int var = 42;
  int& l_val = var;
  int &&r_val = var + 40;
  std::cout << l_val << '\n';
  std::cout << r_val << '\n';
  var = 45;
  std::cout << l_val << '\n';
  std::cout << r_val << '\n';
  return 0;
}
