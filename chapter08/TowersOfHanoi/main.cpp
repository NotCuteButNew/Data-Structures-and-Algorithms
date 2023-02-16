#include <iostream>
#include <ostream>
#include <string>

void TowersOfHanoi(int n, char source, char target, char transit) {
  if (n > 0) {
    TowersOfHanoi(n - 1, source, transit, target);
    std::cout << source << "\t->\t" << target << std::endl;
    TowersOfHanoi(n - 1, transit, source, target);
  }
}

int main(int argc, char **argv) {
  if (argc > 1) {
    int n = std::stoi(argv[1]);
    TowersOfHanoi(n, 'A', 'B', 'C');
  }
  return 0;
}