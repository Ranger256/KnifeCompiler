#pragma once
#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"

typedef struct {
	id idNODE;
} NODE;

extern NODE node;

void parsing();
void parsRecursion(int i);

#endif // !__PARSER__


