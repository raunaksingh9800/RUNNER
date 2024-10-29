
#include "global_data/global_import.h"
#include "global_data/global_var.h"

#include "__sys/sys_call.h"

/**
 * 
 * WARNING - NO ELSE CASE FOR COMMAND NOT FOUND
 * 
*/


using namespace std;


int getOScode(){
    #ifdef _WIN32
    return 0;
    #elif _WIN64
    return 0;
    #elif __APPLE__ || __MACH__
    return 1;
    #elif __linux__
    return 2;
    #elif __FreeBSD__
    return 3;
    #elif __unix || __unix__
    return 4;
    #else
    return 5;
    #endif
}  




int main(int argc, char *arg[]) {   
    
    if (argc<2){
        cerr<<ERROR_COMMAND_NOT_SPECIFIED;
        exit(1);
    }
    else {
        if(string(arg[1])=="-init"){

            return_code = make_commandsTXT();
        }
        else {
            system_call call(FILE_NAME_COMMANDS);
            if(string(arg[1]) == "-list"){
                call.print_key();
            }
            else {
          
                call.run_command(arg[1]);
            }
        }
    }
    return return_code;
}