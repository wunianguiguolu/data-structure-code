#include <iostream>

#include "ParenMatch.hpp"
#include "include/LinkStack.hpp"

bool parenMatch(const char *str){
    LinkStack<char> s;
    while(*str != '\0'){
        switch (*str){
            case '(' : s.push(*str); break;
            case ')' : 
            if (s.isEmpty()){
                std::cout << "An opening bracket '(' is expected!\n" << std::endl;
                return false;
            }
            else {s.pop();}
            break;
        }
        str++;
    }
    if (!s.isEmpty()){
        std::cout << "A closing bracket ')' is expected!\n" << std::endl;
        return false;
    }
    return true;
}