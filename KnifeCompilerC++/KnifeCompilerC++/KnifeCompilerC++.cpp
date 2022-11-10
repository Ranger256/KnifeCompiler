#include "KnifeCompiler.h"

//all headers
#include "Lexer.h"
#include <stdio.h>

std::vector<int> tokens;
std::vector<id> ids;
int lines;

int main()
{
	lexanCode("int i = 5; i=5");
	for (int i = 0; i < tokens.size(); i++)
	{
		printf("%d\n", tokens[i]);
	}
	while (true)
	{

	}
	return 0;
}
