#include <iostream>
#include "asap.h"

int main(int argc, char * argv[]) {
  std::string s;
  asap::datetime now;
  std::cout << "now: " << now << std::endl;
  //%Y-%m-%d %H:%M:%S
  asap::datetime then("2017-12-01 10:00:01", "%c");
  std:: cout << "then: " << then << std::endl;
}
