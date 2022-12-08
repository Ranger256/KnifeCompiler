#include "stdafx.h"
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
	lexanCode("int i = 5; int kg = 3; int func(){ int k = 4 + 6 + i + k ;}");
	//std::vector<id> fs;
	//std::vector<id> f;
	//printf("%d\n", blocks[0].insblock[0].ins.size());
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
	parsing();
	CompileToAssembler();
  //
	//for (int i = fs.size() - 1; i >= 0; i--)
	//{
	//	printf("%s\n", fs[i].name.c_str());
	//}
	//CreatePostfixTokens(ids, ids);
	printf("%s\n", codeAssembler.c_str());
	//printf("%d\n", blocks[0].insblock[0].ins[3].token);
  //  printf("%s\n", blocks[1].parametrs[1].ins[1].name.c_str());
	while (true)
	{

	}
	return 0;
}
