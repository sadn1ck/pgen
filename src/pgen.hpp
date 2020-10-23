#ifndef pgen_H
#define pgen_H

#include <string>

class Pgen {

public:
  /// Constructor
  Pgen();
  ~Pgen();

  /// Constants for command line arguments
  const char *LENGTH = "-l";
  const char *EXTRA = "e";
  const char *HELP = "-h";

  /// Function to show help and options
  void showHelp();

  /// Checks if the paramater passed is a valid number, and between 8 and 100
  bool isValid(const char *param);

  /// Generates a random password by taking in length and whether or not to use
  /// extra characters
  std::string generatePassword(int length, bool extra);

  /// Returns a random index within the limits of the space string
  int getRandomNumber(std::string space);
};

#endif