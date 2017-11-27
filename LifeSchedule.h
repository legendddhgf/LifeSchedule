#include <iostream>
#include "args/args.hxx"

int main(int argc, char** argv);
void AddCommand(args::Subparser &parser);
void StatusCommand(args::Subparser &parser);
void TimeCommand(args::Subparser &parser);
