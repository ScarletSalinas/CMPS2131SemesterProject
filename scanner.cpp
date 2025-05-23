#include "scanner.h"
#include <cctype> // For isdigit(), isspace()

using namespace std;

Scanner::Scanner(const string& input) : input(input) {}

void Scanner::skipWhitespace() {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }
}

bool Scanner::isVariableChar(char c) {
    return isalpha(c);  // a-z, A-Z
}

Token Scanner::getNextToken() {
    skipWhitespace();
    
    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    char current = input[pos];
    
    // Handle negative numbers
    if (current == '-' && pos+1 < input.length() && isdigit(input[pos+1])) {
        string num;
        num += input[pos++]; // Consume '-'
        while (pos < input.length() && isdigit(input[pos])) {
            num += input[pos++];
        }
        return { NUMBER, num };
    }

    // Handle positive numbers 
    if (isdigit(current)) {
        string num;
        while (pos < input.length() && isdigit(input[pos])) {
            num += input[pos++];
        }
        return { NUMBER, num };
    }

    // Handle variables
    if (isVariableChar(current)) {
        pos++; // Advance position after reading variable
        return { VARIABLE, string(1, current) };
    }

    // Handle operators/symbols
    switch(current) {
        case '+': pos++; return { PLUS, "+" };
        case '-': pos++; return { MINUS, "-" };
        case '*': pos++; return { MULTIPLY, "*" };
        case '/': pos++; return { DIVIDE, "/" };
        case '^': pos++; return { EXPONENT, "^" };  
        case '(': pos++; return { LPAREN, "(" };
        case ')': pos++; return { RPAREN, ")" };
        default:  pos++; return { UNKNOWN, string(1, current) };
    }
}