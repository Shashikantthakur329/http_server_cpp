#include <string>
#include <iostream>
#include "./tokenizer.h"

tokenizer::tokenizer(){
    this -> input = "";
    this -> currIndx = 0;
}

tokenizer::tokenizer(std::string s){
    // std::cout<<s<<std::endl;
    this -> input = s;
    this -> currIndx = 0;
}

bool tokenizer::next(){
    if(this -> currIndx == this -> input.size()) return false;
    curr = "";
    while(this -> currIndx < this -> input.size() && this->input[this -> currIndx] != '\r' && this -> input[this -> currIndx] != '\n' && this -> input[this->currIndx] != ' '){
        curr += this->input[this->currIndx];
        this->currIndx++;
    }

    while(this -> currIndx < this -> input.size() && (this->input[this -> currIndx] == '\r' || this -> input[this -> currIndx] == '\n' || this -> input[this->currIndx] == ' ')){
        this->currIndx++;
    }

    return true;
}

std::string tokenizer::getCurrentToken(){
    return curr;
}

std::string tokenizer::getNextToken(){
    if(next()){
        return curr;
    }
    return "";
}