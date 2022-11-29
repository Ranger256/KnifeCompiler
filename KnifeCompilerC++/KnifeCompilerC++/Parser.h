#pragma once
#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"

#define PARSING_SUCCESSFUL 0
#define PARSING_ERROR

static int blocknum = 0;
static int instrnum = 0;

struct instruct {
	std::vector<id> ins;
};

struct block {
	std::vector<instruct> insblock;
};

extern std::vector<block> blocks;

void parsInit();
int parsing();

#endif // !__PARSER__


