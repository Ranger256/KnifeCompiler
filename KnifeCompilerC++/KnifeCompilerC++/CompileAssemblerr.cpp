#include "stdafx.h"
#include"CompilerAssembler.h"

int funcnum = 0;
int blocklocvar = 0;

int CompileNewGlobalVariableIntToAssembler(int blockst, int inst, int k, int valuev) {
	std::string asmCode;

	if (blockst == 0)
	{
		//global variable
		tablsymb.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symb{ _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL ,TOKEN_INT_TYPE, true}));
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
		return _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_ERROR;
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL;
}

int CompileNewLocalVariableIntToAssembler(int blockst, int inst, int k, int valuev) {
	std::string asmCode;

	if (blockst == 0)
	{
		return _COMPILE_ASSEMBLER_VARIABLE_NEW_LOCAL_ERROR;
	}
	else if (blockst > 0) {
		tablsymb.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symb{ _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL, TOKEN_INT_TYPE, false }));
		//if (blocks[blockst].localSymbols.size() < 1)
		//{
		//blocks[blockst].localSymbols.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, 2));
		//}
		//else
		//{
		blocks[blockst].localSymbols.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symbLocalBlock{ blocks[blockst].localSymbols.size() * 2, std::to_string(valuev) }));
		//}
		//printf("%d\n", blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name]);
		// local variable
		asmCode.append("mov dword[esp - ");
		asmCode.append(std::to_string(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].number));
		asmCode.append("], ");
		asmCode.append(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].value);
		asmCode.append(" \n ");
	}

	codeAssembler.append(asmCode.c_str());
	return _COMPILE_ASSEMBLER_VARIABLE_NEW_LOCAL_SUCCESSFULL;
}

int CompileSetGlobalVaraibleIntToAssembler(int blockst, int inst, int k, int value) {

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
			return _COMPILE_ASSEMBLER_VARIABLE_SET_INT_ERROR;
		}
	}
	else
	{
		return  _COMPILE_ASSEMBLER_VARIABLE_SET_INT_ERROR;
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_ASSEMBLER_VARIABLE_SET_INT_SUCCESSFUL;
}

int CompileSetLocalVariableIntToAssembler(int blockst, int inst, int k, int value) {
	std::string asmCode;
	if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].type0 != _COMPILE_ASSEMBLER_FUNCTION)
	{
		if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].global)
		{
			return _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_ERROR;
		}
		else
		{

		}
	}
	else
	{
		return _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_ERROR;
	}
	codeAssembler.append( asmCode.c_str() );
	return _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_SUCCESSFUL;
}


int CompileBlockToAssembler(int _blockst) {
	for (int j = 0; j < blocks[_blockst].insblock.size(); j++)
	{
		for (int k = 0; k < blocks[_blockst].insblock[j].ins.size(); k++)
		{

			switch (blocks[_blockst].insblock[j].ins[k].token)
			{
			case TOKEN_RETURN:
				CompileReturnToAssemler(_blockst, j, k);
				break;
			case TOKEN_IF_WORD:
				CompileIfWordAnnToASM(_blockst, j, k);
				CompileIfWordDefToASM(_blockst, j, k);
				break;
			case TOKEN_ID:
				switch (blocks[_blockst].insblock[j].ins[k].anndef)
				{
				case _COMPILE_ASSEMBLER_CALLING:
					CompileCallFunctionToAssembler(_blockst, j, k);
					break;
				case _COMPILE_ASSEMBLER_NEW_VARIBLE:
					printf("%s\n", "GG");
					if (blocks[_blockst].insblock[j].ins.size() - 1  >= k + 2 )
					{
						CompileNewLocalVariableIntToAssembler(_blockst, j, k, std::stoi( blocks[_blockst].insblock[j].ins[k + 2].name ));
					}
					else
					{
						CompileNewLocalVariableIntToAssembler(_blockst, j,k, 0);
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

	return _COMPILE_ASSEMBLER_BLOCK_SUCCESSFUL;
}

int CompileToAssembler() {

	int i = 0;
	int h2 = 0;

	for (int j = 0; j < blocks[i].insblock.size(); j++)
	{
		for (int k = 0; k < blocks[i].insblock[j].ins.size(); k++)
		{
			switch (blocks[i].insblock[j].ins[k].token)
			{
			case TOKEN_ID:
				if (blocks[i].insblock[j].ins[k - 1].token == TOKEN_INT_TYPE)
				{
					if (blocks[i].insblock[j].ins[k].anndef == _COMPILE_ASSEMBLER_DEFINED) {
						CompileDefntFunctionToAssembler(i, j, k);
						h2++;
						CompileBlockToAssembler(h2);
						break;

					}
					if (blocks[i].insblock[j].ins[k].anndef == _COMPILE_ASSEMBLER_ANNOUNCEMENT) {
						CompileAnucmntFunctionToAssembler(i, j, k);
						break;
					}

					if (blocks[i].insblock[j].ins.size() - 1 > k)
					{
						if (blocks[i].insblock[j].ins[k + 1].token == TOKEN_ASSIGNMENT_SS)
						{
							CompileNewGlobalVariableIntToAssembler(i, j, k, std::stoi(blocks[i].insblock[j].ins[k + 2].name));
							break;
						}
					}
					else
					{
						CompileNewGlobalVariableIntToAssembler(i, j, k, 0);
						break;
					}
				}
				break;
			default:
				break;
			}
		}
	}
	return _COMPILE_ASSEMBLER_SUCCESSFUL;
}
