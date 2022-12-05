#pragma once
#ifndef __COMPILER__
#define __COMPILER__

#define _COMPILE_ASSEMBLER_SUCCESSFUL 0
#define _COMPILE_ASSEMBLER_ERROR 1

#define _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL 2
#define _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_ERROR 3

#define _COMPILE_ASSEMBLER_VARIABLE_SET_INT_SUCCESSFUL 4
#define _COMPILE_ASSEMBLER_VARIABLE_SET_INT_ERROR 5

#define _COMPILE_ASSEMBLER_VARIABLE_NEW_LOCAL_SUCCESSFULL 24
#define _COMPILE_ASSEMBLER_VARIABLE_NEW_LOCAL_ERROR 25

#define _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_SUCCESSFUL 26
#define _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_ERROR 27

#define _COMPILE_ASSEMBLER_VARIABLE_NO_FIND_ERROR 6

#define _COMPILE_ASSEMBLER_BLOCK_SUCCESSFUL 17
#define _COMPILE_ASSEMBLER_BLOCK_ERROR 18

#include "compileAssemblerIncludes.h"
#include "FunctionAssembler.h"
#include "ReturnAssembler.h"

int CompileToAssembler();
int CompileBlockToAssembler( int _blockst );

int CompileNewGlobalVariableIntToAssembler(int blockst, int inst,int k, int valuev);
int CompileSetGlobalVaraibleIntToAssembler(int blockst, int inst, int k, int valuev);
int CompileNewLocalVariableIntToAssembler(int blockst, int inst, int k, int valuev);
int CompileSetLocalVariableIntToAssembler(int blockst, int inst, int k, int valuev);

#include "IfAssembler.h"

#endif // !__COMPILER__


