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
	lexanCode("int i = 4; int main(){ int k = 0; if(){ int hg = 0; } int hgk = 0; } int g = 0; int ty(){ int l = 3;} int gh = 0;");
	parsInit();
	parsing();
	CompileToAssembler();
   // printf("%d\n", blocks.size());
	printf("%s\n", codeAssembler.c_str());
		//printf("%s\n", blocks[3].insblock[0].ins[1].name.c_str());
	while (true)
	{

	}
	return 0;
}
