#pragma once
#ifndef _MATH_PARSER_
#define _MATH_PARSER_

#define PARSING_MATH_EXPR_SUCCESSFULL 31
#define PARSING_MATH_EXPR_ERROR 32

#define PARSING_MATH_CREATE_POSTFIX_TOKENS_SUCCESSFULL 33
#define PARSING_MATH_CREATE_POSTFIX_TOKENS_ERROR 34

#define PARSING_MATH_CREATE_ORDER_NUMBERS_VARIABLES_SUCCESSFULL 35
#define PARSING_MATH_CREATE_ORDER_NUMBERS_VARIABLES_ERROR 36


#include "Lexer.h"
#include <map>
#include <stack>

#include "MathOperations.h"();

void CreatePreorOP( std::map<int, int> &prs );
int CreateOrdersNumbersVariables(std::vector<id> &inse, std::vector<id> insl);
int CreatePostfixTokens(std::vector<id> &inse, std::vector<id> insl);
int ParsingMathExpr( std::vector<id> &inse, std::vector<id> insl);

#endif // !_MATH_PARSER_

