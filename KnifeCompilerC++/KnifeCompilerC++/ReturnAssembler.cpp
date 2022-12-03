#include "stdafx.h"
#include "ReturnAssembler.h"

int CompileReturnToAssemler(int block, int inst, int k) {
	std::string asmCode;

	asmCode.append("pop eax \n pop ebx \n mov esp, ebp \n pop ebp \n ret ");
	asmCode.append(blocks[block].insblock[inst].ins[k + 1].name.c_str());
	asmCode.append(" \n ");

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_RETURN_SUCCESFULL_;
}