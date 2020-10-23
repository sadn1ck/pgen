#include "pgen.hpp"
#include <iostream>
#include <string.h>

/**
 * @brief Valid options occur when
 *  - [pgen -l number e]
 *  - [pgen -l number]
 *  - [pgen help]
 *  - [pgen]
 * @author Anik Das
 */

int main(int argc, char **argv) {
  Pgen pgen;
  if (argc == 1) {
    /** @brief When only binary is executed with no arguments, generate with
     * default options */
    std::string password = pgen.generatePassword(15, true);
    std::cout << "DEFAULT: Generating password of length 15, with extra "
                 "characters enabled\n\t"
              << password << "\n";
    return 0;

  } else if (argc == 2 && strcmp(argv[1], pgen.HELP) == 0) {
    /** @brief When help argument is passed */
    pgen.showHelp();
    return 0;

  } else if (argc == 3 && strcmp(argv[1], pgen.LENGTH) == 0 &&
             pgen.isValid(argv[2])) {
    /** @brief When length argument is passed with valid parameters */
    int length = std::stoi(argv[2]);
    std::string password =
        pgen.generatePassword(length, false); /** @brief Generating password*/
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else if (argc == 4 && strcmp(argv[1], pgen.LENGTH) == 0 &&
             pgen.isValid(argv[2]) && strcmp(argv[3], pgen.EXTRA) == 0) {
    /** @brief When length argument is passed with valid parameters, and, extra
     * characters are enabled */

    int length = std::stoi(argv[2]);
    std::string password =
        pgen.generatePassword(length, true); /** @brief Generating password*/
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else {
    /** @brief When arguments are invalid */
    std::cout << "Argument mismatch! Please check the help section! (Run with "
                 "the -h flag)\n";
    pgen.showHelp();
    return 127;
  }
  return 0;
}
