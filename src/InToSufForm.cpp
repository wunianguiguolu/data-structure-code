#include <iostream>

#include "../include/InToSufForm.hpp"
#include "../include/LinkStack.hpp"

void InToSufForm(const char *instr, char *sufstr){
    LinkStack<char> s;
    int i, j;
    char topCh, hash = '#';
    s.push(hash);
    i = 0; j = 0;
    while(instr[i] != '\0'){
        if((instr[i]) >= '0' && instr[i] <= '9'){
            sufstr[j++] = instr[i++];
        } 
        else{
            switch (instr[i]){
                case '(' :
                    s.push(instr[i]);        
                    break;
                case ')' :
                    topCh = s.pop();
                    while(topCh != '('){
                        sufstr[j++] = topCh;
                        topCh = s.pop();
                    }
                    break;
                case '*' : case '/' :
                    topCh = s.top();
                    while((topCh == '*') || (topCh == '/')){
                        s.pop();
                        sufstr[j++] = topCh;
                        topCh = s.top();
                    } 
                    s.push(instr[i]);
                    break;
                case '+' : case '-' :
                    topCh = s.top();
                    while((topCh != '(') && (topCh != '#')){
                        s.pop();
                        sufstr[j++] = topCh;
                        topCh = s.top();
                    }
                    s.push(instr[i]);
                    break;
            }
            i++;
        }
    }
    topCh = s.top();
    while(topCh != '#'){
        sufstr[j++] = topCh;
        s.pop();
        topCh = s.top();
    }
    sufstr[j] = '\0';
}