#pragma once
#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"
#include "compileAssemblerIncludes.h"
#include "MathParser.h"

#define PARSING_SUCCESSFUL 0
#define PARSING_ERROR
#define PARSING_BLOCK_PARAMS_SUCCESSFULL 23
#define PARSING_BLOCK_PARAMS_ERROR 24
#define PARSING_FUNCTION_W 25
#define PARSING_VARIABLE_W 26
#define PARSING_DADC_SUCCESSFULL 27
#define PARSING_DADC_A_ERROR 28
#define PARSING_DADC_D_ERROR 29
#define PARSING_DADC_C_ERROR 30

static int blocknum = 0;
static int instrnum = 0;

struct instruct {
	std::vector<id> ins;
};
#include <map>

struct symbLocalBlock
{
	unsigned int number;
	std::string value;
};

struct block {
	std::vector<instruct> insblock;
	int variableLocalByteSize;
	int type0;
	std::map<std::string, symbLocalBlock> localSymbols;
	std::vector<instruct> parametrs;
};

extern std::vector<block> blocks;

void parsInit();
int createBlockParams(int blockn, int idsnum);
int defType0(int bl);
int parsing();
int DADC(int idsi, int &i);

#endif // !__PARSER__


