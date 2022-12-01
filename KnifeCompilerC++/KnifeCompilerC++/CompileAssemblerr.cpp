#include "stdafx.h"
#include"CompilerAssembler.h"

int CompileNewVariableIntToAssembler(int block, int inst, int k, int value) {
	std::string asmCode;

	if (block == 0)
	{
		//global variable
		tablsymb.insert(std::make_pair(blocks[block].insblock[inst].ins[k].name, symb{_COMPILE_ASSEMBLER_VARIBLE ,TOKEN_INT_TYPE, true}));
		// blocks[block].insblock[inst].ins[k].global = true;

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
		tablsymb.insert(std::make_pair(blocks[block].insblock[inst].ins[k].name, symb{ _COMPILE_ASSEMBLER_VARIBLE, TOKEN_INT_TYPE, false }));
		// local variable
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL;
}

int CompileSetVaraibleIntToAssembler(int block, int inst, int k, int value) {

	std::string asmCode;
	if (tablsymb[blocks[block].insblock[inst].ins[k].name].type0 != _COMPILE_ASSEMBLER_FUNCTION)
	{
		if (tablsymb[blocks[block].insblock[inst].ins[k].name].global)
		{
			//global
			asmCode.append("mov dword ");
			asmCode.append(blocks[block].insblock[inst].ins[k].name.c_str());
			asmCode.append("[0], ");
			asmCode.append(blocks[block].insblock[inst].ins[k + 2].name.c_str());
			asmCode.append("\n");
		}
		else {
			//local

		}
	}
	else
	{
		return  _COMPILE_ASSEMBLER_VARIABLE_SET_INT_ERROR;
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_SET_INT_SUCCESSFUL;
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
						if (0 <= k - 1)
						{
							if (tablsymb.find(blocks[i].insblock[j].ins[k].name.c_str()) == tablsymb.end()) {
								// not found
								if (blocks[i].insblock[j].ins[k - 1].token == TOKEN_INT_TYPE)
								{
									CompileNewVariableIntToAssembler(i, j, k, std::stoi(blocks[i].insblock[j].ins[k + 2].name));
								}
							}
							else {
								// found
							}
							
						}
						else
						{
							if (tablsymb.find(blocks[i].insblock[j].ins[k].name.c_str()) == tablsymb.end()) {
								return _COMPILE_ASSEMBLER_VARIABLE_NO_FIND_ERROR;
							}
							else {
								switch (tablsymb[blocks[i].insblock[j].ins[k].name].type)
								{
								case TOKEN_INT_TYPE:
									CompileSetVaraibleIntToAssembler(i, j, k, std::stoi(blocks[i].insblock[j].ins[k + 2].name));
									break;
								default:
									break;
								}
							}
							
						}
						break;
					case TOKEN_BRACKET_ROUND_OPEN:

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

