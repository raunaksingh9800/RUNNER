#ifndef PARSER_EN_H
#define PARSER_EN_H


#include "../global_data/global_import.h"
#include "../global_data/global_var.h"

struct packet {
    std::string Heading;
    std::string command;
};

class parser : public file_handler {  // Ensure file_handler is accessible
public:
    std::map<std::string, packet> list_of_command;
    parser(std::string path);
    void parsing();
};

#endif // PARSER_EN_H
