#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

/**
 * 
 * WARNING - NO ELSE CASE FOR COMMAND NOT FOUND
 * 
*/


using namespace std;

const string FILE_NAME_COMMANDS = "./commands.txt";

const string bold_on = "\033[1m";
const string yellow_on = "\033[33m";
const string reset = "\033[0m";

const string RUNNER = "RUNNER";
const string VERSION = "▶ V 1.0 \n";
const string ERROR_NO_FILE = "🔴 \033[31m ERROR \033[0m : no file called commands.txt found OR wrong extention \n";
const string ERROR_COMMAND_NOT_FOUND = "🔴 \033[31m ERROR \033[0m  : Command Not Found! \n";
const string ERROR_COMMAND_NOT_SPECIFIED = "🔴 \033[31m ERROR \033[0m : Please Specify the Command \n ";

int return_code;

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


void _init() {
            cout<<"Created commands.txt succesfully 🎉 \n";
            cout<<'\n'<<bold_on<<"SYNTAX: \n" << reset;
            cout << "-> <Heading> \n> <Argument> \n$ <Command> \n";
            cout<<"\n"<<bold_on<<"EXAMPLE: \n" <<reset;
            cout<<"-> Your First Command \n> first \n$ echo hello \n";
            cout<<"\nCopy the Above 👆 Code into commands.txt \n";
            cout<<"Now Run : runner first \n";
}

struct packet {
    string Heading;
    string command;
};

class file_handler {
private:
    string code;
    
public:
   std::vector<std::string> lines;
    file_handler(string path){
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

    void splitIntoLines() {
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
};


class parser : file_handler {
public:
    map<string , packet> list_of_command;
    parser(string path) : file_handler(path) {
        splitIntoLines();
        parsing();
    };

    void parsing() {
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
};


class system_call : parser {
    public :
        system_call(string path) : parser(path) {

        };
    void run_command(string s) {
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

    void print_key() {
        for (const auto& pair : list_of_command) {
            cout<<"\n⏐⎯⎯⎯ "<<list_of_command[pair.first].Heading<<"\n\t⏐⎯⎯ "<<pair.first<<'\n';
        }
    }

    ~system_call(){
        list_of_command.clear();
    }
};

int main(int argc, char *arg[]) {   
    
    if (argc<2){
        cerr<<ERROR_COMMAND_NOT_SPECIFIED;
        exit(1);
    }
    else {
        if(string(arg[1])=="-init"){
            return_code = system("echo > commands.txt");
            _init();
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