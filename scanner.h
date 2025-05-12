#pragma once
#include <string>

// All possible token types the scanner can produce
enum TokenType {
    DIGIT,          // single digit (0-9)
    UNKNOWN,        // Any unrecognized character
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
};