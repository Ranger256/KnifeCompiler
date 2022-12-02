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
	lexanCode("int i = 4; int main(){ int k = 5; int f = 3;} int hfghjghj = 543; int gh(){int hgf = 0;} int hgfdfd = 0;");
	parsInit();
	parsing();
	CompileToAssembler();
   // printf("%d\n", blocks.size());
	printf("%s\n", codeAssembler.c_str());
	//printf("%s\n", blocks[0].insblock[2].ins[1].name.c_str());
	//printf("%s\n", blocks[2].insblock[0].ins[1].name.c_str());
	while (true)
	{

	}
	return 0;
}
