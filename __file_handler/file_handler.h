
#ifndef FILE_HANDLER
#define FILE_HANDLER

#include "../global_data/global_import.h"



class file_handler {
private:
    std::string code;
public:
   std::vector<std::string> lines;
    file_handler(std::string path);

    void splitIntoLines();
};


int make_commandsTXT();

#endif 
