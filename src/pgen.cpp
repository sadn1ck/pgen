#include "pgen.hpp"
#include <algorithm>
#include <iostream>

Pgen::Pgen() {}
Pgen::~Pgen() {}

bool Pgen::isValid(const char *param) {
  std::string s = std::string(param);
  auto it = s.begin();
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return (!s.empty() && it == s.end()) &&
         (std::stoi(param) >= 8 && std::stoi(param) <= 100);
}

void Pgen::showHelp() {
  std::cout << R"(pgen - Simple password generator
Usage: pgen -l <length> [e]
Options:
    -l        - Length of password you want to generate (8-100)
    e         - Whether to use extra chars like !,?,@
    help      - Display this help
Example:
    $ pgen -l 10
    $ pgen -l 14 e
)";
}

int Pgen::getRandomNumber(std::string space) {
  return (rand() % space.length()) + 1;
}

std::string Pgen::generatePassword(int length, bool extra) {
  std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
  std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string numbers = "0123456789";
  std::string symbols = "!#@$%^&*()=-_?.,";
  std::string password = "";
  std::string space = lowercase + uppercase + numbers;
  password = password + lowercase[Pgen::getRandomNumber(lowercase)];
  password = password + uppercase[Pgen::getRandomNumber(uppercase)];
  password = password + numbers[Pgen::getRandomNumber(numbers)];
  length = length - 3;
  if (extra) {
    space = space + symbols;
    length--;
    password = password + symbols[Pgen::getRandomNumber(symbols)];
  }
  srand((unsigned)time(NULL));
  for (int i = 0; i < length; i++) {
    int randomIndex = Pgen::getRandomNumber(space);
    password = password + space[randomIndex];
  }
  std::random_shuffle(password.begin(), password.end());
  return password;
}
