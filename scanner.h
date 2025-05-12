#pragma once
#include <string>

using namespace std;

// All possible token types the scanner can produce
enum TokenType {
    NUMBER,     // Handles both positive and negative (e.g., "42", "-3")
    VARIABLE,       // Single-letter variable (a-z, A-Z)
    PLUS,           // Addition operator '+'
    MINUS,          // Subtraction operator '-'
    MULTIPLY,       // Multiplication operator '*'
    DIVIDE,         // Division operator '/'
    LPAREN,         // Left parenthesis '('
    RPAREN,         // Right parenthesis ')'
    UNKNOWN,        // Any unrecognized character
    END_OF_INPUT    // Special token indicating end of input
};

// Represents a token with type and literal alue
struct Token {
    TokenType type;     // What kind of token (DIGIT/UNKNOWN/etc.)
    string value;  // The actual character(s) matched
};

// Scans input and breaks it into tokens
class Scanner {
public:
    Scanner(const string& input);  // Initialize scanner with input string
    Token getNextToken();       // Get the next token from input
    
private:
    string input;   // The string being scanned
    size_t pos = 0;     // Current position in input
    
    // Helper to skip whitespace characters
    void skipWhitespace();

    //Helper to check if char is valid for var
    bool isVariableChar(char c);
};