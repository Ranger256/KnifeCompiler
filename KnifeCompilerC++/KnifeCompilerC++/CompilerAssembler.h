#pragma once
#ifndef __COMPILER__
#define __COMPILER__

#define _COMPILE_ASSEMBLER_SUCCESSFUL 0
#define _COMPILE_ASSEMBLER_ERROR 1

#define _COMPILE_ASSEMBLER_VARIABLE_INT_SUCCESSFUL 0
#define _COMPILE_ASSEMBLER_VARIABLE_INT_ERROR 1

#include "Parser.h"

extern std::string codeAssembler;

int CompileToAssembler();

int CompileGlobalNewVariableIntToAssembler(int block, int inst,int k, int value);

#endif // !__COMPILER__


