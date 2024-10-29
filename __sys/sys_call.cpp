

#include "../global_data/global_import.h"
#include "../global_data/global_var.h"

#include "sys_call.h"


system_call::system_call(string path) : parser(path) {

        };

void system_call::run_command(string s) {
        //if(list_of_command.find(s) != list_of_command.end()) {
            string commandStr = list_of_command[s].command;
            const char* command = commandStr.c_str();
            cout<<'\n'<<RUNNER<<endl;
            cout<<VERSION;                                          
    
            cout<<'\n'<<bold_on<<yellow_on<<list_of_command[s].Heading<<reset<<endl;
            cout<<"Your Command:"<<list_of_command[s].command<<endl<<endl;   
            
            return_code = system(command);
        //}
        // else {
        //     cout<<s<<'\n';
        //     cerr<<ERROR_COMMAND_NOT_FOUND;
        //     exit(1);
        // }
    }
void system_call::print_key() {
    for (const auto& pair : list_of_command) {
            cout<<"\n⏐⎯⎯⎯ "<<list_of_command[pair.first].Heading<<"\n\t⏐⎯⎯ "<<pair.first<<'\n';
    }
}

system_call::~system_call() {
    list_of_command.clear();
}