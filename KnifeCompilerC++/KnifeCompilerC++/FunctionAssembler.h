#pragma once
#ifndef _FUNCTION_ASM_
#define _FUNCTION_ASM_

#define _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_SUCCESFULL 7
#define _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_ERROR 8

#define _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_SUCCESFULL 9
#define _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_ERROR 10

#define _COMPILE_FUNCTION_TO_ASSEMBLER_CALL_SUCCESSFULL 21
#define _COMPILE_FUNCTION_TO_ASSEMBLER_CALL_ERROR 22

#define _COMPILE_FUNCTION_CREATE_PARAM_SUCCESSFULL 32
#define _COMPILE_FUNCTION_CREATE_PARAM_ERROR 33
#define _COMPILE_FUNCTION_CALL_PARAM_SUCCESSFULL 34
#define _COMPILE_FUNCTION_CALL_PARAM_ERROR 35

#include "compileAssemblerIncludes.h"

struct pcf {
	std::vector<id> pcfids;
};

int CompileAnucmntFunctionToAssembler(int block, int inst, int k);
int CompileDefntFunctionToAssembler(int block, int inst, int k, int vlbs);
int CompileCallFunctionToAssembler(int block, int inst, int k);
int CompileCreateParamIntFunctionToAssembler(int block, int inst, int k, int numberParam);
int CompileCallParamFunctionToAssembler(int block, int inst, int k);

#endif // !_FUNCTION_ASM_

