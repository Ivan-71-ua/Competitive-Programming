#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cctype>

using namespace std;

// Пріоритет операторів
unordered_map<string, double> precedence = {
        {"min", 5},
        {"max", 5},
        {"^", 4},
        {"*", 3},
        {"/", 3.5},
        {"%", 3},
        {"+", 2},
        {"-", 2},
        {"(", 1}
};

// Функція для перевірки чи є рядок оператором
bool isOperator(const string& token) {
    return precedence.find(token) != precedence.end();
}

// Функція для перевірки чи є рядок функцією
bool isFunction(const string& token) {
    return token == "max" || token == "min";
}

// Функція для конвертації інфіксного виразу в RPN
vector<string> infixToRPN(const vector<string>& tokens) {
    stack<string> opStack;
    vector<string> output;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || (isalpha(token[0]) && token.size() == 1)) { // Якщо операнд (число або змінна)
            output.push_back(token);
        } else if (token == "(") { // Якщо відкрита дужка
            opStack.push(token);
        } else if (token == ")" ) { // Якщо закрита дужка
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop(); // Видаляємо відкриту дужку
            
        }
            else if(token == ",") { // оброка нутрішніх операторів
                while (!opStack.empty() && opStack.top() != "(") {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
            }
            else if (isOperator(token)) { // Якщо оператор
            while (!opStack.empty() && isOperator(opStack.top()) && precedence[opStack.top()] >= precedence[token]) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    // Додаємо всі залишкові оператори в стеку до вихідного рядка
    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

// Функція для розділення рядка на токени
vector<string> tokenize(const string& expression) {
    vector<string> tokens;
    stringstream ss(expression);
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string expression = "min ( b ^ ( a % ( c - 4 ) ) * 4 , max ( b , 2 / a ) + max ( min ( c , 3 ) , 7 ) )";


    vector<string> tokens = tokenize(expression);
    vector<string> rpn = infixToRPN(tokens);

    cout << "RPN: ";
    for (const string& token : rpn) {
        cout << token << " ";
    }
    cout << endl;

    return 0;
}
