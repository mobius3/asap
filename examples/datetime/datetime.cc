#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  setlocale(LC_ALL, "");
  std::string s;
  asap::datetime now;
  asap::datetime then = now + asap::years(10);
  std::cout << "now: " << now << std::endl;
  std::cout << "then: " << then << std::endl;
}
