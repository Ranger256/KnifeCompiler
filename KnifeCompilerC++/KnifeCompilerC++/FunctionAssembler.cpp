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

int CompileDefntFunctionToAssembler(int block, int inst, int k, int vlbs) {
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
		asmcode.append(std::to_string(vlbs));
		asmcode.append(" \n ");

	}
	else
	{
		return _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_ERROR;
	}

	codeAssembler.append(asmcode.c_str());

	return _COMPILE_FUNCTION_TO_ASSEMBLER_DEFINITION_SUCCESFULL;
}

int CompileCallFunctionToAssembler(int block, int inst, int k) {

	std::string asmCode;

	if (block > 0)
	{
		asmCode.append("call ");
		asmCode.append( blocks[block].insblock[inst].ins[k].name.c_str() );
		asmCode.append(" \n ");
	}
	else
	{
		return _COMPILE_FUNCTION_TO_ASSEMBLER_CALL_ERROR;
	}

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_FUNCTION_TO_ASSEMBLER_CALL_SUCCESSFULL;
}

int CompileCreateParamIntFunctionToAssembler(int block, int inst, int k, int numberParam) {

	std::string asmCode;

	tablsymb.insert(std::make_pair(blocks[block].parametrs[inst].ins[k].name, symb{ _COMPILE_ASSEMBLER_VARIABLE_NEW_INT_SUCCESSFUL, TOKEN_INT_TYPE, false }));
	blocks[block].localSymbols.insert(std::make_pair(blocks[block].parametrs[inst].ins[k].name, symbLocalBlock{ blocks[block].localSymbols.size() * 2, "0" }));

	//blocks[block].variableLocalByteSize += 4;

	asmCode.append("mov eax, dword[esp + ");
	asmCode.append( std::to_string(numberParam) );
	asmCode.append(" + ");
	asmCode.append( std::to_string(blocks[block].variableLocalByteSize) );
	asmCode.append(" + 12] \n ");

	asmCode.append("mov dword[esp - ");
	asmCode.append(std::to_string(blocks[block].localSymbols[blocks[block].parametrs[inst].ins[k].name].number));
	asmCode.append("], ");
	asmCode.append("eax");
	asmCode.append(" \n ");
	//asmCode.append("mov dword[esp - ");
	//asmCode.append(std::to_string(blocks[block].localSymbols[blocks[block].parametrs[inst].ins[k].name].number));
	//asmCode.append("], eax \n ");

	codeAssembler.append(asmCode.c_str());

	return _COMPILE_FUNCTION_CREATE_PARAM_SUCCESSFULL;
}

int CompileCallParamFunctionToAssembler(int block, int inst, int k) {

	if (blocks[block].insblock[inst].ins.size() - 1 <= k)
	{
		return _COMPILE_FUNCTION_CALL_PARAM_SUCCESSFULL;
	}
	else
	{
		
		std::vector<pcf> isd;
		std::vector<id> isd2;
		int numisd = 0;
		isd.push_back(pcf{});

		for (int i = k; i < blocks[block].insblock[inst].ins.size(); i++)
		{
			//printf("%d\n", blocks[block].insblock[inst].ins[i].token);
			if (blocks[block].insblock[inst].ins[i].token == TOKEN_COMMA_SS)
			{
			//	printf("%s\n", "GGHHF");
				isd.push_back(pcf{});
				numisd++;

				isd2.push_back(blocks[block].insblock[inst].ins[i - 1]);
			}
			if (blocks[block].insblock[inst].ins[i].token != TOKEN_COMMA_SS && blocks[block].insblock[inst].ins[i].token != TOKEN_END_SS)
			{
				isd[numisd].pcfids.push_back(ids[i]);
			}
			if (i == blocks[block].insblock[inst].ins.size() - 1)
			{
				isd2.push_back(blocks[block].insblock[inst].ins[i]);
			}
		}
		//printf("%d\n", isd2.size());
		for (int i = 0; i < isd2.size(); i++)
		{
			
			codeAssembler.append("push ");
			codeAssembler.append(isd2[i].name.c_str());
			codeAssembler.append(" \n ");
		}

	}
	return _COMPILE_FUNCTION_CALL_PARAM_SUCCESSFULL;
}