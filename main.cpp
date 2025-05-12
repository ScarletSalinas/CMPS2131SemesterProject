#include <cctype>
#include <iostream>
#include "scanner.h"
#include <vector>

using namespace std;

int main() {
    // Get input from user
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    // Create scanner with input
    Scanner scanner(input);
    vector<Token> tokens;   // Store all tokens here

    // Scan tokens until end of input
    while (true) {
        Token token = scanner.getNextToken();
        if (token.type == END_OF_INPUT) {
            break;  // Stop when input ends
        } 
        tokens.push_back(token);    // Add token to list
    }

   // Print all found tokens
    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        std::cout << "Token(Type: ";
        
        // Print token type name
        switch (token.type) {
            case DIGIT:   std::cout << "DIGIT"; break;
            case UNKNOWN: std::cout << "UNKNOWN"; break;
            default:      std::cout << "OTHER";
        }
        
        // Print token value
        std::cout << ", Value: \"" << token.value << "\")\n";
    }

return 0;
}

