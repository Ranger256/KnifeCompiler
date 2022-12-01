#include "stdafx.h"
#include "FunctionAssembler.h"

int CompileAnucmntFunctionToAssembler(int block, int inst, int k) {
	std::string asmcode;

	if (block == 0)
	{
		asmcode.append("section .text\n ");
		asmcode.append("global ");
		asmcode.append(blocks[block].insblock[inst].ins[k].name.c_str());
		asmcode.append("\n ");
	}
	else
	{
		return _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_ERROR;
	}
	codeAssembler.append(asmcode.c_str());
	return _COMPILE_FUNCTION_TO_ASSEMBLER_ANNOUNCEMENT_SUCCESFULL;
}

int CompileDefntFunctionToAssembler(int block, int inst, int k) {
	std::string asmcode;

	if (block == 0)
	{
		asmcode.append("section .text\n ");
		asmcode.append(blocks[block].insblock[inst].ins[k].name.c_str());
		asmcode.append(": \n ");
		asmcode.append("push ebp \n ");
		asmcode.append("mov ebp, esp \n ");
		asmcode.append("push eax \n ");
		asmcode.append("push ebx \n ");
		asmcode.append("sub esp, ");
	//	asmcode.append(std::to_string(blocks[block + 1]));

	}
	else
	{
		return _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_ERROR;
	}

	codeAssembler.append(asmcode.c_str());

	return _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_SUCCESFULL;
}