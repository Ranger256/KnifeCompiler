#pragma once
#ifndef __LEXER__
#define __LEXER__

//symbols
#define TOKEN_END_SS 1
#define TOKEN_SPACE_SS 2
#define TOKEN_COMMA_SS 3
#define TOKEN_DOT_SS 4
#define TOKEN_BRACKET_ROUND_OPEN 11
#define TOKEN_BRACKET_ROUND_CLOSE 12
#define TOKEN_BRACKET_CURLY_OPEN 13
#define TOKEN_BRACKET_CURLY_CLOSE 14
#define TOKEN_BRACKET_SQUARE_OPEN 15
#define TOKEN_BRACKET_SQUART_CLOSE 16
#define TOKEN_ASSIGNMENT_SS 17
#define TOKEN_GREATER_SS 30
#define TOKEN_LESS_SS 31
#define TOKEN_EQUAL_SS 32

//operators
#define TOKEN_DIVISION_OPERATOR 5
#define TOKEN_MULTIPLAY_OPERATOR 6
#define TOKEN_PLUS_OPERATOR 7
#define TOKEN_MINUS_OPERATOR 8

//keywords
#define TOKEN_IF_WORD 9
#define TOKEN_ELSE_WORD 10
#define TOKEN_RETURN 29

//types
#define TOKEN_INT_TYPE 18
#define TOKEN_FLOAT_TYPE 19
#define TOKEN_DOUBLE_TYPE 20
#define TOKEN_STRING_TYPE 21
#define TOKEN_BOOL_TYPE 22

//values
#define TOKEN_INT_VALUE 23
#define TOKEN_FLOAT_VALUE 24
#define TOKEN_DOUBLE_VALUE 25
#define TOKEN_BOOL_VALUE 26
#define TOKEN_STRING_VALUE 27

//ids
#define TOKEN_ID 28

//errors
#define TOKEN_TYPE_ID_ERROR -1

extern int lines;
static char ss[] = {";,*/+-(){}[]=<>"};

typedef struct ident{
	std::string value;
	std::string name;
	int token;
	bool global;
	int anndef;
	int blc;
	//WARNING
//	std::vector<id> paramFUNC;
} id;

extern std::vector<id> ids;

void init();
inline int TypeValueConst(std::string s);
void insert(std::string value,std::string name, int token);
int getID(std::string s);
void lexanCode(std::string s);
int lexan(std::string s);

#endif // !__LEXER__

