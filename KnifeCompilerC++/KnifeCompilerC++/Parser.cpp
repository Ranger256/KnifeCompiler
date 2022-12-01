#include "stdafx.h"
#include "Parser.h"

int k = 0;
int b = 0;

void parsInit() {
	blocks.push_back(block{});
	blocks[0].insblock.push_back(instruct{});
}

int defType0(int bl) {

	int in = blocks[bl].insblock.size() - 1;
	//int k = blocks[bl - 1].insblock[in].ins.size() - 1;
	//int kk = k;

	/*if (blocks[bl - 1].insblock[in].ins[k].token == TOKEN_BRACKET_ROUND_CLOSE)
	{
		while (true)
		{
			printf("%d\n", kk);
			if (blocks[bl - 1].insblock[in].ins[kk].token == TOKEN_BRACKET_ROUND_OPEN)
			{
				break;
			}
			else
			{
				kk--;
			}
		}
	}
	else
	{

	}*/
	//printf("%d\n", bl );
	switch (blocks[bl].insblock[in].ins[0].token)
	{
	case TOKEN_INT_TYPE:
		if (blocks[bl].insblock[in].ins[1].token == TOKEN_ID)
		{
			return _COMPILE_ASSEMBLER_FUNCTION;
		}
		break;
	case TOKEN_IF_WORD:
		return _COMPILE_ASSEMBLER_IF_FUNCTION;
		break;
	default:
		break;
	}
	return _COMPILE_ASSEMBLER_UNDEFINED_ERROR;
}

int parsing() {
	for (int i = 0; i < ids.size(); i++)
	{
		
		switch (ids[i].token)
		{
		case TOKEN_BRACKET_CURLY_OPEN:
			k = instrnum;
			instrnum = 0;
			b = blocknum;
			blocks.push_back(block{});
			blocknum = blocks.size() - 1;
			blocks[blocknum].type0 = defType0(b);
			blocks[blocknum].insblock.push_back(instruct{});
			break;
		case TOKEN_BRACKET_CURLY_CLOSE:
			instrnum = k;
			blocknum = b;
		//	blocknum--;
			blocks[blocknum].insblock.push_back(instruct{});
			//blocks[blocknum].insblock.push_back(instruct{});
			instrnum = blocks[blocknum].insblock.size() - 1;
			b--;
			break;
		case TOKEN_END_SS:
			blocks[blocknum].insblock.push_back(instruct{});
			//instrnum = blocks[blocknum].insblock.size() - 1;
			instrnum++;
			break;
		case TOKEN_ASSIGNMENT_SS:
			if (blocknum > 0)
			{
				if (ids[i - 1].token == TOKEN_ID)
				{
					switch (ids[i - 2].token)
					{
					case TOKEN_INT_TYPE:
						blocks[blocknum].variableLocalByteSize += 4;
						break;
					default:
						break;
					}
				}
				else
				{

				}
			}
			break;
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
