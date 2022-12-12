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

int CompileNewLocalVariableIntToAssembler(int blockst, int inst, int k, std::string valuev) {
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
		blocks[blockst].localSymbols.insert(std::make_pair(blocks[blockst].insblock[inst].ins[k].name, symbLocalBlock{ blocks[blockst].localSymbols.size() * 2, valuev }));
		//}
		//printf("%d\n", blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name]);
		// local variable
		asmCode.append("mov dword[esp - ");
		asmCode.append(std::to_string(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].number));
		asmCode.append("], ");
		asmCode.append(valuev);
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

int CompileSetLocalVariableIntToAssembler(int blockst, int inst, int k) {
	std::string asmCode;
	if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].type0 != _COMPILE_ASSEMBLER_FUNCTION)
	{
		if (tablsymb[blocks[blockst].insblock[inst].ins[k].name].global)
		{
			return _COMPILE_ASSEMBLER_VARIABLE_SET_LOCAL_ERROR;
		}
		else
		{
			//asmCode.append("mov edx, 0 \n ");
			int top = blocks[blockst].insblock[inst].ins.size() - 1;
			if (k + 3 < top) {
				codeAssembler.append("mov edx, 0 \n ");
				CompileSetValueVariable(blockst, inst, k, top);
				asmCode.append("mov dword[esp - ");
				asmCode.append(std::to_string(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].number));
				asmCode.append("], edx \n ");
			}
			else
			{
				switch (blocks[blockst].insblock[inst].ins[top].token)
				{
				case TOKEN_INT_VALUE:
					asmCode.append("mov dword[esp - ");
					asmCode.append(std::to_string(blocks[blockst].localSymbols[blocks[blockst].insblock[inst].ins[k].name].number));
					asmCode.append("], ");
					asmCode.append( blocks[blockst].insblock[inst].ins[top].name.c_str() );
					asmCode.append(" \n ");
					break;
				case TOKEN_ID:
					codeAssembler.append("mov edx, 0 \n ");
					if (tablsymb[blocks[blockst].insblock[inst].ins[top].name].global) {
						codeAssembler.append("mov edx, [");
						codeAssembler.append(blocks[blockst].insblock[inst].ins[top].name.c_str());
						codeAssembler.append("] \n ");
					}
					else
					{
						//	codeAssembler.append("mov edx, 0 \n ");
						CompileTakeValueLocalVariableToAssembler(blockst, blocks[blockst].insblock[inst].ins[top].name);
						codeAssembler.append("mov edx, eax \n ");
					}
				//	CompileNewLocalVariableIntToAssembler(_blockst, j, k, "edx");
					break;
				default:
					break;
				}
			}
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

	//if (blocks[_blockst].type0 == _COMPILE_ASSEMBLER_FUNCTION) {
		//for (int i = 0; i < blocks[_blockst].parametrs.size(); i++)
		//{
			//for (int j = 0; j < blocks[_blockst].parametrs[i].ins.size(); j++)
			//{
				//tablsymb.insert(std::make_pair(blocks[_blockst].parametrs[i].ins[j].name, symb{ _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL, TOKEN_INT_TYPE, false }));
			//} 
		//}
	//}

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
					CompileCallParamFunctionToAssembler(_blockst, j, k);
					CompileCallFunctionToAssembler(_blockst, j, k);
					break;
				case _COMPILE_ASSEMBLER_SET_VARIABLE:
				
					CompileSetLocalVariableIntToAssembler(_blockst, j, k);
					break;
				case _COMPILE_ASSEMBLER_NEW_VARIBLE:
					//printf("%s\n", "GG");
					if (blocks[_blockst].insblock[j].ins.size() - 1  >= k + 2 )
					{
						
						
						int top = blocks[_blockst].insblock[j].ins.size() - 1;
					
						if (k + 3 < top)
						{
							codeAssembler.append("mov edx, 0 \n ");
							CompileSetValueVariable(_blockst, j, k, top);
							CompileNewLocalVariableIntToAssembler(_blockst, j, k, "edx");
						}
						else
						{
							
							switch (blocks[_blockst].insblock[j].ins[top].token)
							{
							case TOKEN_INT_VALUE:
								CompileNewLocalVariableIntToAssembler(_blockst, j, k, blocks[_blockst].insblock[j].ins[top].name);
								break;
							case TOKEN_ID:
								if (tablsymb[blocks[_blockst].insblock[j].ins[top].name].global) {
									codeAssembler.append("mov edx, [");
									codeAssembler.append(blocks[_blockst].insblock[j].ins[top].name.c_str());
									codeAssembler.append("] \n ");
								}
								else
								{
								//	codeAssembler.append("mov edx, 0 \n ");
									CompileTakeValueLocalVariableToAssembler(_blockst,blocks[_blockst].insblock[j].ins[top].name);
									codeAssembler.append("mov edx, eax \n ");
								}
								CompileNewLocalVariableIntToAssembler(_blockst, j, k, "edx");
								break;
							default:
								break;
							}
						}
						
						
					}
					else
					{
						CompileNewLocalVariableIntToAssembler(_blockst, j, k, 0);
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
			printf("%s\n", blocks[i].insblock[0].ins[3].name.c_str());
			switch (blocks[i].insblock[j].ins[k].token)
			{
			case TOKEN_ID:
				if (blocks[i].insblock[j].ins[k - 1].token == TOKEN_INT_TYPE)
				{
					if (blocks[i].insblock[j].ins[k].anndef == _COMPILE_ASSEMBLER_DEFINED) {
						
						h2++;
						CompileDefntFunctionToAssembler(i, j, k, blocks[h2].variableLocalByteSize);
						if (blocks[h2].parametrs[0].ins.size() > 0 && blocks[h2].parametrs.size() > 0)
						{
							int bni = 0;
							for (int bpi = 0; bpi < blocks[h2].parametrs.size(); bpi++)
							{
								bni += 4;
								CompileCreateParamIntFunctionToAssembler(h2, bpi, 1, bni);
								//CompileCreateParamIntFunctionToAssembler(h2, 1, 1, 8);
							}
						}
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
