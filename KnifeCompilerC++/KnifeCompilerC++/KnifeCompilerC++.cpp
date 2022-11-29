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

int main()
{
	// 
	lexanCode("int i = 5;");
	parsInit();
	parsing();
	CompileToAssembler();
	//printf("%d\n", blocks.size());
	 printf("%s\n", codeAssembler.c_str());
	//for (int i = 0; i < ids.size(); i++)
//	{
		//printf("%d\n", ids[i].token);
	//}
	while (true)
	{

	}
	return 0;
}
