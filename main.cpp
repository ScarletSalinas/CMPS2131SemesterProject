#include <cctype>  
#include <iostream>
#include <vector>
using namespace std;

// Part A: enumerate the list of valid token types according to 
// our grammar.  We only recognize digits, everything else is 
// invalid (unknown).  We also specify when there is no more input
// available for the scanner
enum TokenType {
    DIGIT,
    UNKNOWN,
    END_OF_INPUT
};

// Part B: Define the structure of each token. For now a token 
// will have a type, and a value
struct Token {
    TokenType type;
    string value;
};

struct Token {
    TokenType type;
    string value;
};

Token getNextToken(const string& input, size_t& pos);


int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    size_t position = 0;
    vector<Token> tokens;

    while (true) {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT) {
            break;
        } 
        tokens.push_back(token);
    }

    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        cout << "Token(Type: ";
        switch (token.type) {
            case DIGIT: 
                cout << "DIGIT";
                break;
            case UNKNOWN: 
                cout << "UNKNOWN";
                break;
            default: cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}

Token getNextToken(const string& input, size_t& pos) {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    if(pos >= input.length()) {
        return
        {
            END_OF_INPUT,
            ""
        };
    }

    if(isdigit(input[pos])) {
        string digit(1, input[pos]);
        pos++;
        return
        {
            DIGIT, // token type
            digit  // string value
        };
    }
    return
    {
        UNKNOWN,
        string(1, input[pos++])
    };
}
