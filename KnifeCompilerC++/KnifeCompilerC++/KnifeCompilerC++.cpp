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
	lexanCode("int i = 6; int main(){} int nam(){}");
	parsInit();
	parsing();
	CompileToAssembler();
  //  printf("%d\n", blocks[0].insblock[5].ins.size());
	printf("%s\n", codeAssembler.c_str());
	//printf("%d\n", blocks[0].insblock[0].ins[3].token);
  //  printf("%s\n", blocks[1].parametrs[1].ins[1].name.c_str());
	while (true)
	{

	}
	return 0;
}
