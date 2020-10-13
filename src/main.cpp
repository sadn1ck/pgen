#include <iostream>
#include <string.h>

#define LENGTH "-l"
#define EXTRA "e"
#define HELP "-h"

void showHelp();
bool isValid(const char *param);
std::string generatePassword(int length, bool extra);

int main(int argc, char **argv) {
  /*
  Valid options occur when
  1 - [pgen -l number e]
  2 - [pgen -l number]
  3 - [pgen help]
  4 - [pgen]
  */
  if (argc == 1) {
    // Valid - 1
    std::string password = generatePassword(15, true);
    std::cout << "DEFAULT: Generating password of length 15, with extra "
                 "characters enabled\n\t"
              << password << "\n";
    return 128;

  } else if (argc == 2 && strcmp(argv[1], HELP) == 0) {
    // Valid - 2

    showHelp();
    return 0;

  } else if (argc == 3 && strcmp(argv[1], LENGTH) == 0 && isValid(argv[2])) {
    // Valid - 3
    int length = std::stoi(argv[2]);
    std::string password = generatePassword(length, false);
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else if (argc == 4 && strcmp(argv[1], LENGTH) == 0 && isValid(argv[2]) &&
             strcmp(argv[3], EXTRA) == 0) {
    // Valid - 4

    int length = std::stoi(argv[2]);
    std::string password = generatePassword(length, true);
    std::cout << "Generated password is: \n\t" << password << "\n";
    return 0;

  } else {
    // Invalid
    std::cout << "Invalid arguments!\n";
    // showHelp();
    return 0;
  }
  showHelp();
  return 0;
}

/// Checks if the paramater passed is a valid number between 8 and 100
bool isValid(const char *param) {
  std::string s = std::string(param);
  auto it = s.begin();
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return (!s.empty() && it == s.end()) &&
         (std::stoi(param) >= 8 && std::stoi(param) <= 100);
}

/// Generates a random password by taking in length and whether or not to use
/// extra characters
std::string generatePassword(int length, bool extra) {
  std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
  std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string numbers = "0123456789";
  std::string symbols = "!#@$%^&*()=-_?.,";
  std::string password = "";
  std::string space = lowercase + uppercase + numbers;
  if (extra) {
    space = space + symbols;
  }
  srand((unsigned)time(NULL));
  for (int i = 0; i < length; i++) {
    int randomIndex = (rand() % space.length()) + 1;
    password = password + space[randomIndex];
  }
  return password;
}

/// Function to show help and options
void showHelp() {
  std::cout << R"(pgen - Simple password generator
Usage: pgen -l <length> [e]
Options:
    -l        - Length of password you want to generate (8-100)
    e         - Whether to use extra chars like !,?,@
    help      - Display this help
Example:
    $ pgen 10
    $ pgen 14 e
)";
}
