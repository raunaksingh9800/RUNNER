
#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#include "global_import.h"

using namespace std; 


extern int return_code;
const string FILE_NAME_COMMANDS = "./commands.txt";

const string bold_on = "\033[1m";
const string yellow_on = "\033[33m";
const string reset = "\033[0m";

const string RUNNER = "RUNNER";
const string VERSION = "▶ V 1.0 \n";
const string ERROR_NO_FILE = "🔴 \033[31m ERROR \033[0m : no file called commands.txt found OR wrong extention \n";
const string ERROR_COMMAND_NOT_FOUND = "🔴 \033[31m ERROR \033[0m  : Command Not Found! \n";
const string ERROR_COMMAND_NOT_SPECIFIED = "🔴 \033[31m ERROR \033[0m : Please Specify the Command \n ";
const string ERROR_COMMANDSTXT_NOT_CREATED = "🔴 \033[31m ERROR \033[0m : Unable to Create file.\n";
const string SYNTAX = "-> <Heading> \n> <Argument> \n$ <Command> \n";

#endif 
