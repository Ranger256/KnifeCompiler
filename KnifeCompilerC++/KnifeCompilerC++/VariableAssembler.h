#pragma once
#ifndef _VARIABLE_ASSEMBLER
#define _VARIABLE_ASSEMBLER

#include <string>
#include "compileAssemblerIncludes.h"

#define _COMPILE_TAKE_VALUE_VARIABLE_SUCCESSFULL 30
#define _COMPILE_TAKE_VALUE_VARIABLE_ERROR 31
#define _COMPILE_SET_VALUE_VARIABLE_SUCCESSFULL 36
#define _COMPILE_SET_VALUE_VARIABLE_ERROR 37

int CompileTakeValueLocalVariableToAssembler(int blockst, std::string nameVariable);
int CompileSetValueVariable(int _blockst, int j, int k, int top);

#endif // !_VARIABLE_ASSEMBLER

