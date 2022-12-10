#include "stdafx.h"
#include "VariableAssembler.h"

int CompileTakeValueLocalVariableToAssembler(int blockst,std::string nameVariable) {
	std::string asmCode;

	asmCode.append("mov eax, dword[esp - ");

	asmCode.append(std::to_string(blocks[blockst].localSymbols[nameVariable].number));
	//asmCode.append(std::to_string(tablsymb[nameVariable].numStackLocal).c_str());

	asmCode.append("] \n ");

	codeAssembler.append(asmCode.c_str());
	return _COMPILE_TAKE_VALUE_VARIABLE_SUCCESSFULL;
}

int CompileSetValueVariable(int _blockst, int j, int k, int top) {

	for (int ki = top; ki >= k + 2; ki--)
	{
		//printf("%s\n", blocks[_blockst].insblock[j].ins[ki].name.c_str());
		switch (blocks[_blockst].insblock[j].ins[ki].token)
		{
		case TOKEN_PLUS_OPERATOR:

			if (blocks[_blockst].insblock[j].ins[ki + 1].name != "+")
			{

				if (blocks[_blockst].insblock[j].ins[ki + 1].token == TOKEN_ID)
				{
					if (tablsymb[blocks[_blockst].insblock[j].ins[ki + 1].name].global)
					{
						codeAssembler.append("add edx, [");
						codeAssembler.append(blocks[_blockst].insblock[j].ins[ki + 1].name.c_str());
						codeAssembler.append("] ");
					}
					else
					{
						CompileTakeValueLocalVariableToAssembler(_blockst,blocks[_blockst].insblock[j].ins[ki + 1].name);

						codeAssembler.append("add edx, eax");//codeAssembler.append(std::to_string(tablsymb[blocks[_blockst].insblock[j].ins[ki + 1].name].numStackLocal));
					}
				}
				else
				{
					codeAssembler.append("add edx, ");
					codeAssembler.append(blocks[_blockst].insblock[j].ins[ki + 1].name.c_str());
				}


				codeAssembler.append(" \n ");
			}
			if (blocks[_blockst].insblock[j].ins[ki + 2].name != "+")
			{

				if (blocks[_blockst].insblock[j].ins[ki + 2].token == TOKEN_ID) {
					if (tablsymb[blocks[_blockst].insblock[j].ins[ki + 2].name].global)
					{
						codeAssembler.append("add edx, [");
						codeAssembler.append(blocks[_blockst].insblock[j].ins[ki + 2].name.c_str());
						codeAssembler.append("] ");
					}
					else
					{
						CompileTakeValueLocalVariableToAssembler(_blockst,blocks[_blockst].insblock[j].ins[ki + 2].name);
						//codeAssembler.append("eax");
						codeAssembler.append("add edx, eax");
						//codeAssembler.append(std::to_string(tablsymb[blocks[_blockst].insblock[j].ins[ki + 2].name].numStackLocal));
					}
				}
				else
				{
					codeAssembler.append("add edx, ");
					codeAssembler.append(blocks[_blockst].insblock[j].ins[ki + 2].name.c_str());
				}
				codeAssembler.append(" \n ");
			}
			break;
		default:
			break;
		}
	}

	return _COMPILE_SET_VALUE_VARIABLE_SUCCESSFULL;
}