#include "./parser.h"
// #include "./tokenizer.h"
#include <iostream>

parser::parser(tokenizer tk){
    this -> tk = tk;
}

bool parser::parse_http(){
    while(this->tk.next()){
        std::cout<<this->tk.getCurrentToken()<<", ";
    }
    // std::cout<<"in"<<std::endl;
    // while(this->tk.getNextToken() != "")
    // {
    //     std::cout<<this->tk.getCurrentToken()<<", ";
    // }
    // std::cout<<"out"<<std::endl;
    std::string curr = "";
    if(this->tk.next()) curr = this->tk.getCurrentToken();
    else {std::cout<<"bad_request"<<std::endl; return false;}

    if(curr == "GET"){
        parse_get();
        if(this->tk.next()) curr = this->tk.getCurrentToken();
        else {std::cout<<"bad_request"<<std::endl; return false;}
        
        //send file

        if(this->tk.next()) curr = this->tk.getCurrentToken();
        else {std::cout<<"bad_request"<<std::endl; return false;}

    }
    return false;
}

std::string parser::parse_get(){
    if(this -> tk.next()){
        // store filename, and send data 
    }
}

std::string parser::parse_put(){

}

std::string parser::get_data(){
    return "";
}




