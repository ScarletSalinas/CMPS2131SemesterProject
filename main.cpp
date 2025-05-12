#include <iostream>
#include <vector>
#include "scanner.h"

using namespace std;

/* Pretty-prints token type */
string tokenTypeToString(TokenType type) {
    switch (type) {
        case NUMBER:   return "NUMBER";
        case VARIABLE: return "VARIABLE";
        case PLUS:    return "PLUS";
        case MINUS:   return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE:  return "DIVIDE";
        case LPAREN:  return "LPAREN";
        case RPAREN:  return "RPAREN";
        case UNKNOWN: return "UNKNOWN";
        default:      return "OTHER";
    }
}

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    Scanner scanner(input);
    vector<Token> tokens;

    /* Tokenize input */
    while (true) {
        Token token = scanner.getNextToken();
        if (token.type == END_OF_INPUT) break;
        tokens.push_back(token);
    }

    /* Print tokens */
    for (const auto& token : tokens) {
        cout << "Token(" 
                  << "Type: " << tokenTypeToString(token.type) << ", "
                  << "Value: \"" << token.value << "\")\n";
    }

    return 0;
}