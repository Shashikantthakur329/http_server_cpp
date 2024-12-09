#ifndef _INCLUDE_PARSER
#define _INCLUDE_PARSER
#include "./tokenizer.h"

class parser{
    public:
    tokenizer tk;
    std::string data;
    parser(tokenizer tk);
    bool parse_http();
    std::string parse_get();
    std::string parse_put();
    std::string get_data();
};







#endif

