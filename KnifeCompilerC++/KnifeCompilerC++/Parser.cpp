#include "stdafx.h"
#include "Parser.h"

int k = 0;

void parsInit() {
	blocks.push_back(block{});
	blocks[0].insblock.push_back(instruct{});
}

int parsing() {
	for (int i = 0; i < ids.size(); i++)
	{
		
		switch (ids[i].token)
		{
		case TOKEN_BRACKET_CURLY_OPEN:
			k = instrnum;
			instrnum = 0;
			blocks.push_back(block{});
			blocknum++;
			blocks[blocknum].insblock.push_back(instruct{});
			break;
		case TOKEN_BRACKET_CURLY_CLOSE:
			instrnum = k;
			blocknum--;
			break;
		case TOKEN_END_SS:
			blocks[blocknum].insblock.push_back(instruct{});
			instrnum++;
		default:
			break;
		}

		if (ids[i].token != TOKEN_BRACKET_CURLY_CLOSE && ids[i].token != TOKEN_BRACKET_CURLY_OPEN && ids[i].token != TOKEN_END_SS)
		{
			 blocks[blocknum].insblock[instrnum].ins.push_back(ids[i]);
		}

	}

	return PARSING_SUCCESSFUL;
}
