#include <iostream>
#include <bits/stdc++.h> 
#include <list>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

struct Token {  // 一个简单的结构体，成员只有一个字符串，用来储存数值或符号
    string text;
    Token(string text) : text(text) {}
    double doubleValue() {  // 将string类型转化为double类型
        stringstream ss(text);
        double value;
        ss >> value;
        return value;
    }
};

class Parser {

    struct Tree {      // 二叉树
        Token token;   // 储存数值或符号
        Tree * left;   // 指向左子树的指针
        Tree * right;  // 指向右子树的指针

        Tree(Token token) : token(token) {
            left = 0;
            right = 0;
        }
        ~Tree() {
            if (left != 0) delete left;
            if (right != 0) delete right;
        }
    };

    Tree * expression;  // 指向表达式二叉树的指针
    double result;      // 整个表达式的计算结果

    // ！！！计算表达式的值
    static double execute(Tree * expression) { 
        if (expression->left == 0) {   // ！！！左子树为空时，token储存的是当前子树的值
            double value = expression->token.doubleValue();
            return value;
        } else {   // ！！！左右子树均存在，分别计算左右子树的值，再根据符号进行四则运算
            double left_data = execute(expression->left);
            double right_data = execute(expression->right);   
            if (expression->token.text == "+"){
                return left_data + right_data;
            }
            if (expression->token.text == "-"){
                return left_data - right_data;
            }
            if (expression->token.text == "*"){
                return left_data * right_data;
            }
            if (expression->token.text == "/"){
                return left_data / right_data;
            }
        }
    }

public:  
    Parser() {
        expression = 0;
    }

    ~Parser() {
        if (expression != 0) delete expression;
    }

    // 执行表达式计算
    double execute() {
        if (expression != 0) {
            result = execute(expression);
            delete expression;
            expression = 0;
        }
        return result;
    }

    // 创建一棵新树, 这里用list模拟实现栈的功能
    void create(list<Tree*> &subTreeStack, list<string> &operatorStack) {
        Tree* node = new Tree(Token(operatorStack.back()));  // 新子树值为此时符号栈的顶部
        operatorStack.pop_back();              // pop掉符号栈的栈顶
        node->right = subTreeStack.back();     // 新树的右孩子为子树栈的顶部
        subTreeStack.pop_back();               // pop掉子树栈的栈顶
        if (!subTreeStack.empty()) {
            node->left = subTreeStack.back();  // 新树的左孩子为此时子树栈的顶部
            subTreeStack.pop_back();
        } else {  // 考虑特殊情况: -5、-0、+0 
            Tree* temp = new Tree(Token("0"));
            node->left = temp;                 // 新树的左孩子为一个值为0的子树
        }
        subTreeStack.push_back(node);   // 新树加进栈顶
    }

    // ！！！将表达式构建成一棵二叉树
    bool parse(string str) {
        Tree* node;
        list<Tree*> subTreeStack;
        list<string> operatorStack;
        int i, j;
        int local_length;
        string topCh, hash = "#";
        operatorStack.push_back(hash);
        i = 0; j = 0;
        int position = 0;
        while (position < str.length()){
            if(str[position] >= '0' && str[position] <= '9'){
                local_length = 1;
                if(str[position + local_length] == '.'){
                    local_length++;
                    while(str[position + local_length] >= '0' && str[position] <= '9'){
                        local_length++;
                    }
                    if(str[position + local_length] == '.'){
                        return false;
                    }
                    node = new Tree(Token(str.substr(position, local_length)));
                    subTreeStack.push_back(node);
                    position = position + local_length;
                }
                else if (str[position + local_length] >= '0' && str[position + local_length] <= '9'){
                    local_length++;
                    if(str[position + local_length] == '.'){
                        local_length++;
                    }
                    while(str[position + local_length] >= '0' && str[position] <= '9'){
                        local_length++;
                    }
                    if(str[position + local_length] == '.'){
                        return false;
                    }
                    node = new Tree(Token(str.substr(position, local_length)));
                    subTreeStack.push_back(node);
                    position = position + local_length;
                }
                else{
                    node = new Tree(Token(str.substr(position, local_length)));
                    subTreeStack.push_back(node);
                    position = position + local_length;
                }
            }
            else{
                switch (str[position]){
                    case '(' :
                        operatorStack.push_back((str.substr(position, 1)));
                        break;
                    case ')' :
                        topCh = operatorStack.back();
                        while(topCh != "("){
                            create(subTreeStack, operatorStack);
                            topCh = operatorStack.back();
                        }
                        operatorStack.pop_back();
                        break;
                    case '*' : case '/' :
                        topCh = operatorStack.back();
                        while((topCh == "*") || (topCh == "/")){
                            create(subTreeStack, operatorStack);
                            topCh = operatorStack.back();
                        } 
                        operatorStack.push_back((str.substr(position, 1)));
                        break;
                    case '+' : 
                        topCh = operatorStack.back();
                        while((topCh != "(") && (topCh != "#")){
                            create(subTreeStack, operatorStack);
                            topCh = operatorStack.back();
                        }
                        operatorStack.push_back((str.substr(position, 1)));
                        break; 
                    case '-' :
                        topCh = operatorStack.back();
                        if(topCh == "("){
                            node = new Tree(Token("0"));
                            subTreeStack.push_back(node);
                        }
                        while((topCh != "(") && (topCh != "#")){
                            create(subTreeStack, operatorStack);
                            topCh = operatorStack.back();
                        }
                        operatorStack.push_back((str.substr(position, 1)));
                        break; 
                    default:
                        return false;        
                }
                position++;
            }
        }
        topCh = operatorStack.back();
        // cout << topCh << endl;
        while(topCh != "#"){
            create(subTreeStack, operatorStack);
            topCh = operatorStack.back();
            // sufstr[j++] = topCh;
            // opStack.pop();
            // topCh = opStack.top();
            // cout << "Wrong!" << endl;
        }
        expression = subTreeStack.back();
        return true;
    }                                 
};

int main(int argc, char const *argv[]) {  
    Parser p = Parser();  
    string expression;
    while (cin >> expression) {
        if (expression.length() > 0) {  // 不处理空字符串
            if(p.parse(expression))
            	cout << fixed << setprecision(3) <<  p.execute() << endl;
			else
				cout << "invalid"<<endl;
        }
    }
    return 0;
}