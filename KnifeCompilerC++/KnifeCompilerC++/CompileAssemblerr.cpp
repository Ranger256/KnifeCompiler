#include "stdafx.h"
#include"CompilerAssembler.h"

int funcnum = 0;

int CompileNewVariableIntToAssembler(int blockst, int inst, int k, int valuev) {
	std::string asmCode;

	if (blockst == 0)
	{
		//global variable
		tablsymb.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symb{_COMPILE_ASSEMBLER_VARIBLE ,TOKEN_INT_TYPE, true}));
		// blocks[block].insblock[inst].ins[k].global = true;

		asmCode = "section .text \n global ";
		
		asmCode.append(blocks[blockst].insblock[inst].ins[k].name.c_str());

		asmCode.append("\n section .data\n ");

		asmCode.append(blocks[blockst].insblock[inst].ins[k].name.c_str());

		asmCode.append(": dw ");

		asmCode.append(std::to_string(valuev));

		asmCode.append("\n");


	}
	else if(blockst > 0)
	{
		tablsymb.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symb{ _COMPILE_ASSEMBLER_VARIBLE, TOKEN_INT_TYPE, false }));
		//if (blocks[blockst].localSymbols.size() < 1)
		//{
			//blocks[blockst].localSymbols.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, 2));
		//}
		//else
		//{
		blocks[blockst].localSymbols.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symbLocalBlock{ blocks[blockst].localSymbols.size() * 2, std::to_string (valuev) }));
		//}
		//printf("%d\n", blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name]);
		// local variable
		asmCode.append("mov dword[esp - ");
		asmCode.append( std::to_string( blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].number ) );
		asmCode.append("], ");
		asmCode.append(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].value);
		asmCode.append(" \n ");
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL;
}

int CompileSetVaraibleIntToAssembler(int blockst, int inst, int k, int value) {

	std::string asmCode;
	if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].type0 != _COMPILE_ASSEMBLER_FUNCTION)
	{
		if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].global)
		{
			//global
			asmCode.append("mov dword ");
			asmCode.append(blocks[blockst].insblock[inst].ins[k].name.c_str());
			asmCode.append("[0], ");
			asmCode.append(blocks[blockst].insblock[inst].ins[k + 2].name.c_str());
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

int CompileBlockToAssembler(int _blockst) {

	for (int j = 0; j < blocks[_blockst].insblock.size(); j++)
	{
		for (int k = 0; k < blocks[_blockst].insblock[j].ins.size(); k++)
		{

			switch (blocks[_blockst].insblock[j].ins[k].token)
			{

			case TOKEN_ID:

				if (blocks[_blockst].insblock[j].ins[k].anndef == _COMPILE_ASSEMBLER_DEFINED) {
					CompileDefntFunctionToAssembler(_blockst, j, k);

				}
				if (blocks[_blockst].insblock[j].ins[k].anndef == _COMPILE_ASSEMBLER_ANNOUNCEMENT) {
					CompileAnucmntFunctionToAssembler(_blockst, j, k);
				}

				switch (blocks[_blockst].insblock[j].ins[k + 1].token)
				{
				case TOKEN_ASSIGNMENT_SS:
					if (0 <= k - 1)
					{
						if (tablsymb.find(blocks[_blockst].insblock[j].ins[k].name.c_str()) == tablsymb.end()) {
							// not found
							if (blocks[_blockst].insblock[j].ins[k - 1].token == TOKEN_INT_TYPE)
							{
								CompileNewVariableIntToAssembler(_blockst, j, k, std::stoi(blocks[_blockst].insblock[j].ins[k + 2].name));
							}
						}
						else {
							// found
						}

					}
					else
					{
						if (tablsymb.find(blocks[_blockst].insblock[j].ins[k].name.c_str()) == tablsymb.end()) {
							return _COMPILE_ASSEMBLER_VARIABLE_NO_FIND_ERROR;
						}
						else {
							switch (tablsymb[blocks[_blockst].insblock[j].ins[k].name].type)
							{
							case TOKEN_INT_TYPE:
								CompileSetVaraibleIntToAssembler(_blockst, j, k, std::stoi(blocks[_blockst].insblock[j].ins[k + 2].name));
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

	return _COMPILE_ASSEMBLER_BLOCK_SUCCESSFUL;
}

int CompileToAssembler() {

	//CompileBlockToAssembler(0);
	int i = 0;
	//int j = 0;
	//int k = 0;
	int h = 0;
	int h1 = 0;
	int h2 = 0;
	//for (int i = 0; i < blocks.size(); i++)
	//{
		for(int j = 0; j < blocks[i].insblock.size(); j++)
		{
			for (int k = 0; k < blocks[i].insblock[j].ins.size(); k++)
			{

				switch (blocks[i].insblock[j].ins[k].token)
				{

				case TOKEN_ID:

					if (blocks[i].insblock[j].ins[k ].anndef == _COMPILE_ASSEMBLER_DEFINED) {
						CompileDefntFunctionToAssembler(i, j, k);
						h2++;
						i = h2;
						h = j;
						h1 = k;
						j = 0;
						k = 0;
					}
					if (blocks[i].insblock[j].ins[k ].anndef == _COMPILE_ASSEMBLER_ANNOUNCEMENT) {
						CompileAnucmntFunctionToAssembler(i, j, k);
					}
					
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
				if (i > 0)
				{
					//
					if (j == blocks[i].insblock.size() - 2 && k == blocks[i].insblock[j].ins.size() - 1)
					{
						j = h;
						k = h1;
						h = 0;
						h1 = 0;
						i = 0;
						//printf("%s\n", "GG");
					}
				}
			}
		}
	//}*/

	return _COMPILE_ASSEMBLER_SUCCESSFUL;
}

