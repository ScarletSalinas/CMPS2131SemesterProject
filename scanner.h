#pragma once
#include <string>

// All possible token types the scanner can produce
enum TokenType {
    DIGIT,          // single digit (0-9)
    VARIABLE,       // Single-letter variable (a-z, A-Z)
    PLUS,           // Addition operator '+'
    MINUS,          // Subtraction operator '-'
    MULTIPLY,       // Multiplication operator '*'
    DIVIDE,         // Division operator '/'
    UNKNOWN,        // Any unrecognized character
    LPAREN,         // Left parenthesis '('
    RPAREN,         // Right parenthesis ')'
    END_OF_INPUT    // Special token indicating end of input
};

// Represents a single token found in input
struct Token {
    TokenType type;     // What kind of token (DIGIT/UNKNOWN/etc.)
    std::string value;  // The actual character(s) matched
};

// Scans input and breaks it into tokens
class Scanner {
public:
    Scanner(const std::string& input);  // Initialize scanner with input string
    Token getNextToken();       // Get the next token from input
    
private:
    std::string input;   // The string being scanned
    size_t pos = 0;     // Current position in input
    
    // Helper to skip whitespace characters
    void skipWhitespace();

    //Helper to check if char is valid for var
    bool isVariableChar(char c);
};