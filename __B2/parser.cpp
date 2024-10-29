


#include "../global_data/global_import.h"
#include "../global_data/global_var.h"
#include "parser.h"



parser::parser(string path) : file_handler(path) {
        splitIntoLines();
        parsing();
};

void parser::parsing() {
    for(int i = 0; i < lines.size()  ; i++){
            if (lines[i].at(0) == '-' && lines[i].at(1) == '>' ){
                if(lines[i+1].at(0) == '>') {
                    if(lines[i+2].at(0) == '$'){
                     list_of_command[lines[i+1].substr(2)].Heading = lines[i].substr(3);
                    list_of_command[lines[i+1].substr(2)].command = lines[i+2].substr(2);

                    }
                }
            } 
            
        }
        lines.clear();
}