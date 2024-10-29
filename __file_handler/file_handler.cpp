

#include "../global_data/global_import.h"
#include "../global_data/global_var.h"

#include "file_handler.h"

using namespace std;


file_handler::file_handler(string path){
        fstream input(path, ios::in);
        if (input.fail())
        {
            cerr << ERROR_NO_FILE;
            exit(1);
        }
        stringstream stream_code;
        stream_code << input.rdbuf();
        code = stream_code.str();
        input.close();
    };

void file_handler::splitIntoLines() {
        string currentLine;
        for (char c; c<code.length(); c++) {
            if (c == '\n') {
                if (!currentLine.empty()) {
                    if(currentLine.at(0)=='-' && currentLine.at(1)=='>') {
                        lines.push_back(currentLine);
                        
                    }
                    if(currentLine.at(0) == '>' || currentLine.at(0) == '$') {
                       lines.push_back(currentLine); 
                    }
                    currentLine.clear();
                }
            } else {
                currentLine += c;
            }
        }
        if (!currentLine.empty()) {
            lines.push_back(currentLine);
        }
     
    }


int make_commandsTXT() {
    std::ofstream file("commands.txt");

    if (file.is_open()) {
        file << "-> Your First Command\n";
        file << "> first\n";
        file << "$ echo Working\n";
        
        file.close();
        
        cout<<"Created commands.txt succesfully 🎉 \n";
        cout<<'\n'<<bold_on<<"SYNTAX: \n" << reset;
        cout << SYNTAX;
        cout<<"\nNow Run : runner first \n";
        return 0;
    } else {
        return 1;
        std::cerr << ERROR_COMMANDSTXT_NOT_CREATED;
    }

}