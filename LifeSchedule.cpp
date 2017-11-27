/**
 * @file LifeSchedule.cpp
 * @brief Main file for Life Schedule project
 * @author August Valera

 * @version 0.1
 * @date 2017-11-26
 */

#include "LifeSchedule.h"

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
  args::Command add(commands, "add", "add an activity/task", &AddCommand);
  args::Command status(commands, "status", "check current progress on activities", &StatusCommand);
  args::Command time(commands, "time", "update progress on activity",
      &TimeCommand);
  args::HelpFlag help(parser, "help", "display this help menu", {'h', "help"});

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

void AddCommand(args::Subparser &parser) {
  args::ValueFlag<std::string> message(parser, "MESSAGE", "activity message", {'m'});
  parser.Parse();
}

void StatusCommand(args::Subparser &parser) {
  parser.Parse();
}

void TimeCommand(args::Subparser &parser) {
  parser.Parse();
}
