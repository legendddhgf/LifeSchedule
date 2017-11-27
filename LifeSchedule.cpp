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
  args::ArgumentParser parser(
      "A scheduler for human operating systems.",
      "Project under development at http://github.com/legendddhgf/LifeSchedule"
      );
  args::Group commands(parser, "commands");
  args::Command add(commands, "add", "add an activity to your life");
  args::Command status(commands, "status", "see your life status");
  args::HelpFlag help(parser, "help", "display this help menu", {'h', "help"});

  // Execute parser
  try {
    parser.ParseCLI(argc, argv);
    if(add) {
      std::cout << "Adding an activity" << std::endl;
    } else if(status) {
      std::cout << "Checking status" << std::endl;
    }
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
