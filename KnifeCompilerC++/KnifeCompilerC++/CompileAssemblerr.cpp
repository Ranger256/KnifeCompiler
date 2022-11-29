#include "stdafx.h"
#include"CompilerAssembler.h"

int CompileGlobalNewVariableIntToAssembler(int block, int inst, int k, int value) {
	std::string asmCode;

	if (block == 0)
	{
		asmCode = "section .text \n global ";
		
		asmCode.append(blocks[block].insblock[inst].ins[k].name.c_str());

		asmCode.append("\n section .data\n ");

		asmCode.append(blocks[block].insblock[inst].ins[k].name.c_str());

		asmCode.append(": dw ");

		asmCode.append(std::to_string(value));

		asmCode.append("\n");


	}
	else if(block > 0)
	{

	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_INT_SUCCESSFUL;
}

int CompileToAssembler() {

	for (int i = 0; i < blocks.size(); i++)
	{
		for (int j = 0; j < blocks[i].insblock.size(); j++)
		{
			for (int k = 0; k < blocks[i].insblock[j].ins.size(); k++)
			{

				switch (blocks[i].insblock[j].ins[k].token)
				{

				case TOKEN_ID:

					switch (blocks[i].insblock[j].ins[k + 1].token)
					{
					case TOKEN_ASSIGNMENT_SS:
						if (blocks[i].insblock[j].ins[k - 1].token == TOKEN_INT_TYPE)
						{
							CompileGlobalNewVariableIntToAssembler(i, j, k, std::stoi(blocks[i].insblock[j].ins[k + 2].name));
						}
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}

			}
		}
	}

	return _COMPILE_ASSEMBLER_SUCCESSFUL;
}