#ifndef _INCLUDE_TOKENIZER
#define _INCLUDE_TOKENIZER
#include <string>
class tokenizer{
    public:
    std::string input;
    std::string curr;
    int currIndx;
    bool next();
    std::string getCurrentToken();
    std::string getNextToken();
    tokenizer();
    tokenizer(std::string s);
};
#endif