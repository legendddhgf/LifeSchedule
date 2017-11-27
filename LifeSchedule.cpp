/**
 * @file LifeSchedule.cpp
 * @brief Main file for Life Schedule project
 * @author August Valera

 * @version 0.1
 * @date 2017-11-26
 */

#include <iostream>
#include "args/args.hxx"

/**
 * @brief Main of the program
 *
 * @param argc Argument count
 * @param argv Command line argument list
 *
 * @return Exit status
 */
int main(int argc, char** argv) {

  // Create parser
  args::ArgumentParser parser("This is a test program.", "This goes after the options.");
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});

  // Execute parser
  try {
    parser.ParseCLI(argc, argv);
  } catch(args::Help) {
    std::cout << parser;
    return 0;
  } catch(args::ParseError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }
  return 0;
}
