#include "scanner.h"
#include <cctype> // For isdigit(), isspace()

// Constructor - stores input string
Scanner::Scanner(const std::string& input) : input(input) {}

// Moves position past any whitespace
void Scanner::skipWhitespace() {
    while (pos < input.length() && isspace(input[pos])) {
        pos++; // Advance past spaces/tabs/newlines
    }
}

// Main scanning function - returns next token
Token Scanner::getNextToken() {
    skipWhitespace(); // First skip any whitespace
    
    // Check for end of input
    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    // Handle digits (0-9)
    if (isdigit(input[pos])) {
        std::string digit(1, input[pos]); // Convert char to string
        pos++; // Move to next character
        return { DIGIT, digit }; // Return digit token
    }

    // If not a digit, treat as unknown
    std::string unknown(1, input[pos]);
    pos++;
    return { UNKNOWN, unknown };
}