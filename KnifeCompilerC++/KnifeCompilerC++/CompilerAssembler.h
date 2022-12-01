#pragma once
#ifndef __COMPILER__
#define __COMPILER__

#define _COMPILE_ASSEMBLER_SUCCESSFUL 0
#define _COMPILE_ASSEMBLER_ERROR 1

#define _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL 2
#define _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_ERROR 3

#define _COMPILE_ASSEMBLER_VARIABLE_SET_INT_SUCCESSFUL 4
#define _COMPILE_ASSEMBLER_VARIABLE_SET_INT_ERROR 5

#define _COMPILE_ASSEMBLER_VARIABLE_NO_FIND_ERROR 6

#include "compileAssemblerIncludes.h"

int CompileToAssembler();

int CompileNewVariableIntToAssembler(int block, int inst,int k, int value);
int CompileSetVaraibleIntToAssembler(int block, int inst, int k, int value);

#endif // !__COMPILER__


