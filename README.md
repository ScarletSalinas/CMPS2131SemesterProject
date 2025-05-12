# Arithmetic Expression Scanner

## Overview

A lexical analyzer that tokenizes arithmetic expressions with:

  - Full number support (positive/negative integers)

  - Variables (single-letter)

  - Operators (+, -, *, /, ^)

  - Parentheses grouping

## Token Specifications

| Token Type  | Pattern      | Examples   | Notes                      |
|-------------|--------------|------------|----------------------------|
| `NUMBER`    | `-?[0-9]+`   | `24`, `-3` | Negative numbers supported |
| `VARIABLE`  | `[a-z, A-Z]` | `x`, `Y`   | Single-letter only         |
| `EXPONENT`  | `^`          | `^`        | Single-character           |
| `OPERATORS` | `+`, `-`, `*`, `/` | `+`  | All binary operations      |
| `PARENS`    | `(`, `)`     | `(`        | Grouping expressions       |

## Build & Test
```bash
g++ -std=c++11 *.cpp -o scanner
./scanner
> Enter expression: 2^-3
[NUMBER "2", EXPONENT "^", NUMBER "-3"]
```

## Design Philosophy
**1. Character Foundation**:
   ```cpp
   // Most tokens are single-character
   case '^': return {EXPONENT, "^"};  // Exponentiation
   case 'x': return {VARIABLE, "x"};  // Variables
   ```
**2. Practical Exceptions**:
   ```cpp
   // Multi-digit numbers for usability
   "42" → NUMBER "42" (not DIGIT "4", DIGIT "2")
   "-5" → NUMBER "-5" (unary negation)
   ```

**3. Key Features**:
   ```cpp
  // Negative number detection
  if (current == '-' && isdigit(next_char)) {
      // Returns NUMBER "-42"
  }
  
  // Strict 1-character tokens for:
  // - Variables (a-z)
  // - Operators (except numbers)
   ```

## Example Tokenizations
### Input: `2^(x + 1)`
```
NUMBER "2"
EXPONENT "^"
LPAREN "("
VARIABLE "x"
PLUS "+"
NUMBER "1"
RPAREN ")"
```
## Link to Video
[Watch demo here](https://www.youtube.com/watch?v=H-e5-19HO7Y) 

## References
  - LLM: DeepSeek, for tutoring, learning necessary concepts, and for guidance when needed.
