#include "scanner.h"
#include <cctype> // For isdigit(), isspace()

using namespace std;

// Constructor - stores input string
Scanner::Scanner(const string& input) : input(input) {}

// Moves position past any whitespace
void Scanner::skipWhitespace() {
    while (pos < input.length() && isspace(input[pos])) {
        pos++; // Advance past spaces/tabs/newlines
    }
}

// Check if character is valid for a variable name
bool Scanner::isVariableChar(char c) {
    return isalpha(c);  // Returns true for a-z, A-Z
}

// Main scanning function - returns next token
Token Scanner::getNextToken() {
    skipWhitespace(); // First skip any whitespace
    
    // Check for end of input
    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    char current = input[pos++];    // Get current character and advance
    
    // Check for digits
    if (isdigit(current)) {
        return { DIGIT, string(1, current) }; // Return digit token
    }

    // Check for variables
    if (isVariableChar(current)) {
        return { VARIABLE, std::string(1, current) };
    }

    // Check for arithmetic operators
    switch(current) {
        case '+' : return { PLUS, "+"};
        case '-' : return { MINUS, "-"};
        case '*' : return { MULTIPLY, "*"};
        case '/' : return { DIVIDE, "/"};
        case '(': return { LPAREN, "(" };
        case ')': return { RPAREN, ")" };
        default: return { UNKNOWN, string(1, current) };
    }
}