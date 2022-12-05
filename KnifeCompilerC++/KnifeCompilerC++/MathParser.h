#pragma once
#ifndef _MATH_PARSER_
#define _MATH_PARSER_

#define PARSING_MATH_EXPR_SUCCESSFULL 31
#define PARSING_MATH_EXPR_ERROR 32

#include "Lexer.h"

int ParsingMathExpr( std::vector<id> &inse, std::vector<id> insl);

#endif // !_MATH_PARSER_

