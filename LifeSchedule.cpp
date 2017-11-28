/**
 * @file LifeSchedule.cpp
 * @brief Main file for the Life Schedule project
 * @author August Valera

 * @version 0.1
 * @date 2017-11-26
 */

#include "LifeSchedule.h"

int main(int argc, char** argv) {

  // Create parser
  args::ArgumentParser parser(
      "A scheduler for human operating systems.",
      "Project under development at http://github.com/legendddhgf/LifeSchedule"
      );
  args::Group commands(parser, "commands");
  args::Command add(commands, "add", "add an activity/task", &AddCommand);
  args::Command edit(commands, "edit", "edit an activity/task", &EditCommand);
  args::Command status(commands, "status",
      "check current progress on activities", &StatusCommand);
  args::Command tag(commands, "tag", "add a category to a task",
      &TagCommand);
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
  args::ValueFlag<std::string> msg(parser, "MESSAGE", "activity message",
      {'m'});
  parser.Parse();

  std::string message;
  if(msg) {
    message = args::get(msg);
  } else {
    // This should actually open up in $EDITOR
    std::cout << "Body text of the new activity: ";
    std::cin >> message;
  }
  std::cout << "Adding new activity: " << message << std::endl;
}

void EditCommand(args::Subparser &parser) {
  args::ValueFlag<std::string> msg(parser, "MESSAGE", "activity message",
      {'m'});
  args::Positional<std::string> act(parser, "ACT", "activity to edit");
  parser.Parse();

  if(act) {
    std::string message;
    if(msg) {
      message = args::get(msg);
    } else {
      // This should actually open up in $EDITOR
      std::cout << "Body text of edited activity: ";
      std::cin >> message;
    }
    std::cout << "Editing activity: " << args::get(act) << " to " << message <<
      std::endl;
  }
}

void StatusCommand(args::Subparser &parser) {
  parser.Parse();
}

void TagCommand(args::Subparser &parser) {
  args::ValueFlag<std::string> add(parser, "TAG", "tag to add", {'a', "add"});
  args::ValueFlag<std::string> del(parser, "TAG", "tag to delete", {'d',
      "delete"});
  args::PositionalList<std::string> acts(parser, "ACTS", "activities to tag");
  parser.Parse();

  for(auto &&act : acts) {
    if(add) {
      std::cout << "Adding " << args::get(add) << " to activity " << act <<
        std::endl;
    }
    if(del) {
      std::cout << "Deleting " << args::get(add) << " from activity " <<
        act << std::endl;
    }
  }
}
