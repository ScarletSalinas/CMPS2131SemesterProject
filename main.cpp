#include <cctype>
#include <iostream>
#include "scanner.h"
#include <vector>

using namespace std;

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

   // Print all tokens with description
    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        std::cout << "Token(Type: ";
        
        // Print token type name
        switch (token.type) {
            case DIGIT:   std::cout << "DIGIT"; break;
            case PLUS:    std::cout << "PLUS"; break;
            case MINUS:   std::cout << "MINUS"; break;
            case MULTIPLY: std::cout << "MULTIPLY"; break;
            case DIVIDE:  std::cout << "DIVIDE"; break;
            case LPAREN:  std::cout << "LPAREN"; break;
            case RPAREN:  std::cout << "RPAREN"; break;
            case UNKNOWN: std::cout << "UNKNOWN"; break;
        }
        
        // Print token value
        std::cout << ", Value: \"" << token.value << "\")\n";
    }

return 0;
}

