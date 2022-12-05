#include "stdafx.h"
#include "IfAssembler.h"

int g = 0;

int CompileIfWordAnnToASM(int _blockst, int inst, int k) {
	g++;
	int f = k;

	while (true)
	{
		if (blocks[_blockst].insblock[inst].ins[f].token == TOKEN_LESS_SS) {
			CompileIfWordLessToASM(_blockst, inst, f);
			break;
		}
		f++;
	}


	return _COMPILE_ASSEMBLER_IF_SUCCESSFULL;
}

int CompileIfWordDefToASM(int _blockst, int inst, int k) {

	std::string asmCode;

	asmCode.append("L");
	asmCode.append(std::to_string(g));
	asmCode.append(": \n ");
	
	codeAssembler.append(asmCode.c_str());
	CompileBlockToAssembler(_blockst + 1);
	asmCode = "";
	//asmCode.append( " \n ");
	g++;
	asmCode.append("jmp L");
	asmCode.append(std::to_string(g));
	asmCode.append(" \n ");
	asmCode.append("L");
	asmCode.append(std::to_string(g));
	asmCode.append(": \n ");
	codeAssembler.append(asmCode.c_str());
	

	//printf("%d\n", blocks[2].type0);

	return _COMPILE_ASSEMBLER_IF_SUCCESSFULL;
}

int CompileIfWordGreaterToASM(int _blockst, int inst, int k){

	return _COMPILE_ASSEMBLER_IF_SUCCESSFULL;
}

int CompileIfWordLessToASM(int _blockst, int inst, int k) {

	std::string asmCode;

	asmCode.append("cmp ");
	asmCode.append(blocks[_blockst].insblock[inst].ins[k - 1].name.c_str());
	asmCode.append(", ");
	asmCode.append(blocks[_blockst].insblock[inst].ins[k + 1].name.c_str());
	asmCode.append(" \n jg L");
     asmCode.append( std::to_string(g).c_str() );
	 asmCode.append("\n jmp L");
	 asmCode.append(std::to_string(g + 1).c_str());
	asmCode.append(" \n ");

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_IF_SUCCESSFULL;
}

int CompileIfWordEqualToASM(int _blockst, int inst, int k) {

	return _COMPILE_ASSEMBLER_IF_SUCCESSFULL;
}