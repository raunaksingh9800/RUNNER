#ifndef SYS_CALL
#define SYS_CALL

#include "../global_data/global_import.h"
#include "../global_data/global_var.h"

class system_call : public parser {  // Public inheritance from parser
public:
    system_call(std::string path);
    void run_command(std::string s);
    void print_key();
    ~system_call();
};

#endif
