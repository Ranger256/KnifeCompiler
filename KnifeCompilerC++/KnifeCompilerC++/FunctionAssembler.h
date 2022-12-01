#pragma once
#ifndef _FUNCTION_ASM_
#define _FUNCTION_ASM_

#define _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_SUCCESFULL 7
#define _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_ERROR 8

#define _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_SUCCESFULL 9
#define _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_ERROR 10

#include "compileAssemblerIncludes.h"

int CompileAnucmntFunctionToAssembler(int block, int inst, int k);
int CompileDefntFunctionToAssembler(int block, int inst, int k);

#endif // !_FUNCTION_ASM_

