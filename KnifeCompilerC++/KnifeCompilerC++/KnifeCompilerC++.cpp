﻿#include "stdafx.h"
#include "KnifeCompiler.h"

//all headers
#include "Parser.h"
#include "Lexer.h"
//#include <stdio.h>
#include "CompilerAssembler.h"
std::vector<id> ids;
std::vector<block> blocks;
int lines = 1;
std::string codeAssembler;
std::map<std::string, symb> tablsymb;

int main()
{
	// 
	lexanCode("int i = 5; int kg = 3; int func(int a, int b){ b =  5+i + a; int ac = 4;} int main(int argc){func(3, 4);} int dg = 0;");
	//std::vector<id> fs;
	//std::vector<id> f;
	
	//f.push_back(ids[13 + 5]);
	//f.push_back(ids[14 + 5]);
	//f.push_back(ids[15 + 5]);
	//f.push_back(ids[16 + 5]);
	//f.push_back(ids[17 + 5]);
	//f.push_back(ids[18 + 5]);
	//f.push_back(ids[19 + 5]);
	//f.push_back(ids[20 + 5]);
	//f.push_back(ids[21 + 5]);
	//ParsingMathExpr (fs, f);
	parsInit();
	//printf("%s\n", "GG");
	parsing();
	
	//printf("%s\n", blocks[2].insblock[0].ins[5].name.c_str());
	CompileToAssembler();
  //
	//for (int i = fs.size() - 1; i >= 0; i--)
	//{
	//	printf("%s\n", fs[i].name.c_str());
	//}
	//CreatePostfixTokens(ids, ids);
	printf("%s\n", codeAssembler.c_str());
	//printf("%d\n", blocks[2].variableLocalByteSize);
   //printf("%d\n", blocks[1].parametrs[0].ins[1].name.c_str());
	while (true)
	{

	}
	return 0;
}
