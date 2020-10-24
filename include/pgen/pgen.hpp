#ifndef pgen_H
#define pgen_H

#include <string>

/**
 * @brief The pgen class
 * @author Anik Das
 * @date 23 October, 2020
 */
class Pgen
{

public:
    /**
   * Constructor
   */
    Pgen();

    /**
   * Destructor
   */
    ~Pgen();

    const char *LENGTH = "-l"; /**< CLI argument of the length */

    const char *EXTRA = "e"; /**< CLI argument of whether to use extra chars */

    const char *HELP = "-h"; /**< CLI argument to show help section */

    /**
   * @brief Function to show help and options
   */
    void showHelp();

    /**
   * @brief Checks if the paramater passed is a valid number, and between 8 and
   * 100
   * @param parameter - the command line argument passed as length (after -l)
   * @returns whether or not parameter is valid
   */
    bool isValid(const char *parameter);

    /**
   * @brief Returns a random password by taking in length and whether or not to
   * use extra characters
   * @param length - the valid length passed as command line arguments
   * @param extra - boolean value to denote if extra characters are to be used
   * @returns the generated password
   */
    std::string generatePassword(int length, bool extra);

    /**
   * @brief Returns a random index within the size of the string
   * @param space - string from which you want the random index
   * @returns an index within the length of the space string
   */
    int getRandomNumber(std::string space);
};

#endif