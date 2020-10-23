#include "pgen.hpp"
#include <iostream>
#include <string.h>

int main(int argc, char **argv) {
  Pgen pgen;
  /*
  Valid options occur when
  1 - [pgen -l number e]
  2 - [pgen -l number]
  3 - [pgen help]
  4 - [pgen]
  */
  if (argc == 1) {
    // Valid - 1
    std::string password = pgen.generatePassword(15, true);
    std::cout << "DEFAULT: Generating password of length 15, with extra "
                 "characters enabled\n\t"
              << password << "\n";
    return 0;

  } else if (argc == 2 && strcmp(argv[1], pgen.HELP) == 0) {
    // Valid - 2

    pgen.showHelp();
    return 0;

  } else if (argc == 3 && strcmp(argv[1], pgen.LENGTH) == 0 &&
             pgen.isValid(argv[2])) {
    // Valid - 3
    int length = std::stoi(argv[2]);
    std::string password = pgen.generatePassword(length, false);
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else if (argc == 4 && strcmp(argv[1], pgen.LENGTH) == 0 &&
             pgen.isValid(argv[2]) && strcmp(argv[3], pgen.EXTRA) == 0) {
    // Valid - 4

    int length = std::stoi(argv[2]);
    std::string password = pgen.generatePassword(length, true);
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else {
    // Invalid
    std::cout << "Invalid arguments!\n";
    return 127;
  }
  pgen.showHelp();
  return 0;
}
