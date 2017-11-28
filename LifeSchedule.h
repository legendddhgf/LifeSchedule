/**
 * @file LifeSchedule.h
 * @brief Main header for the Life Schedule project
 * @author August Valera

 * @version 0.1
 * @date 2017-11-27
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
int main(int argc, char** argv);


/**
 * @brief Adding an activity
 *
 * @param parser
 */
void AddCommand(args::Subparser &parser);

/**
 * @brief Editing an activity
 *
 * @param parser
 */
void EditCommand(args::Subparser &parser);

/**
 * @brief Checking the status
 *
 * @param parser
 */
void StatusCommand(args::Subparser &parser);


/**
 * @brief Categories
 *
 * @param parser
 */
void TagCommand(args::Subparser &parser);
