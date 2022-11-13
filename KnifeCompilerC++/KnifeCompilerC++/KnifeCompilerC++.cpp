#include "KnifeCompiler.h"

//all headers
#include "Parser.h"
#include "Lexer.h"
#include <stdio.h>

std::vector<id> ids;
NODE node;
int lines = 1;

int main()
{
	lexanCode("double i = 5.5; double i = 5.3 {{}");
	parsing();
	printf("%d\n", getID("i"));
	//for (int i = 0; i < ids.size(); i++)
//	{
		//printf("%d\n", ids[i].token);
	//}
	while (true)
	{

	}
	return 0;
}
