#include <cctype>
#include <iostream>
#include "scanner.h"
#include <vector>

using namespace std;

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
    // Get input from user
    string input;
    cout << "Enter arithmetic expression: ";
    getline(cin, input);

    // Create scanner with input
    Scanner scanner(input);
    vector<Token> tokens;   // Store all tokens here

    // Tokenize input
    while (true) {
        Token token = scanner.getNextToken();
        if (token.type == END_OF_INPUT) {
            break;  // Stop when input ends
        } 
        tokens.push_back(token);    // Add token to list
    }

   // Print tokens
   for (const auto& token : tokens) {
    std::cout << "Token(" 
              << "Type: " << tokenTypeToString(token.type) << ", "
              << "Value: \"" << token.value << "\")\n";
    }

    return 0;
}
