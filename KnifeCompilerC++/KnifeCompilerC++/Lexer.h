#pragma once
#ifndef __LEXER__
#define __LEXER__

#include <string>
#include <vector>

//symbols
#define TOKEN_END_SS 1001
#define TOKEN_SPACE_SS 1002
#define TOKEN_COMMA_SS 1003
#define TOKEN_DOT_SS 1004
#define TOKEN_BRACKET_ROUND_OPEN 1011
#define TOKEN_BRACKET_ROUND_CLOSE 1012
#define TOKEN_BRACKET_CURLY_OPEN 1013
#define TOKEN_BRACKET_CURLY_CLOSE 1014
#define TOKEN_BRACKET_SQUARE_OPEN 1015
#define TOKEN_BRACKET_SQUART_CLOSE 1016
#define TOKEN_ASSIGNMENT_SS 1017

//operators
#define TOKEN_DIVISION_OPERATOR 1005
#define TOKEN_MULTIPLAY_OPERATOR 1006
#define TOKEN_PLUS_OPERATOR 1007
#define TOKEN_MINUS_OPERATOR 1008

//keywords
#define TOKEN_IF_WORD 1009
#define TOKEN_ELSE_WORD 1010

//types
#define TOKEN_INT_TYPE 1018
#define TOKEN_FLOAT_TYPE 1019
#define TOKEN_DOUBLE_TYPE 1020
#define TOKEN_STRING_TYPE 1021
#define TOKEN_BOOL_TYPE 1022

//values
#define TOKEN_INT_VALUE 1023
#define TOKEN_FLOAT_VALUE 1024
#define TOKEN_DOUBLE_VALUE 1025
#define TOKEN_BOOL_VALUE 1026
#define TOKEN_STRING_VALUE 1027

#define TOKEN_ID 1028

extern int lines;
extern std::vector<int> tokens;
static char ss[] = {";,*/+-(){}[]="};

typedef struct {
	std::string value;
	std::string name;
	int token;
} id;

extern std::vector<id> ids;

void init();
void insert(std::string value,std::string name, int token);
int getID(std::string s);
void lexanCode(std::string s);
int lexan(std::string s);

#endif // !__LEXER__

