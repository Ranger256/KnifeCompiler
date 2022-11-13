#include "Parser.h"

void parsRecursion(int i) {
	int l = i;
	if (ids[i].token == TOKEN_BRACKET_CURLY_OPEN){

		while (ids[l].token != TOKEN_BRACKET_CURLY_CLOSE)
		{
			l++;
			
		}

	}

	


}

void parsing() {

	for (int i = 0; i < ids.size(); i++)
	{
		parsRecursion(i);
	}
}
