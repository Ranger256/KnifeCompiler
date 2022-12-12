#include "stdafx.h"
#include "Parser.h"

int k = 0;
int b = 0;
int bb = 0;
int adids = 0;
int idn = 0;
int ad = 0;
int idn2 = 0;

void parsInit() {
	blocks.push_back(block{});
	blocks[0].insblock.push_back(instruct{});
}

int DADC(int idsi, int &i) {
	idn = idn2;
	if (ids[idsi + 1].token == TOKEN_BRACKET_ROUND_OPEN)
	{
		adids = idsi;

		ad = idsi;

		while (true)
		{
			if (ids[ad].token == TOKEN_BRACKET_ROUND_CLOSE) {
				idn = ad;
				idn2 = idn;
				ad++;
				//i++;
				break;
			}
			else
			{
				
			//	if (ids[ad].token != TOKEN_BRACKET_ROUND_OPEN && ids[ad].token != TOKEN_BRACKET_ROUND_OPEN)
				//{
					//blocks[blocknum].insblock[instrnum].ins.push_back(ids[ad]);
				//}
				ad++;
			}

		}
		ad++;
		if (ids[ad - 1].token == TOKEN_BRACKET_CURLY_OPEN && ids[idsi - 1].token == TOKEN_INT_TYPE) {
			ids[idsi].anndef = _COMPILE_ASSEMBLER_DEFINED;
			ids[idsi].blc = blocknum + 1;
			ad++;
		}
		if (ids[ad - 1].token == TOKEN_END_SS && ids[idsi - 1].token == TOKEN_INT_TYPE) {
			//printf("%s\n", "ann");
			ids[idsi].anndef = _COMPILE_ASSEMBLER_ANNOUNCEMENT;
			ad++;
		}
		if (ids[ad - 1].token == TOKEN_END_SS)
		{
			printf("%s\n", "call");
			ids[idsi].anndef = _COMPILE_ASSEMBLER_CALLING;
			ad++;
			idn = 0;
			
		}
	}
	else
	{
		switch (ids[idsi - 1].token)
		{
		case TOKEN_INT_TYPE:

			ids[idsi].anndef = _COMPILE_ASSEMBLER_NEW_VARIBLE;
			return PARSING_DADC_SUCCESSFULL;
			break;
		default:
			if (ids[idsi + 1].token == TOKEN_ASSIGNMENT_SS)
			{
				ids[idsi].anndef = _COMPILE_ASSEMBLER_SET_VARIABLE;
				return PARSING_DADC_SUCCESSFULL;
			}
			ids[idsi].anndef = _COMPILE_ASSEMBLER_TAKE_VALUE_VARIABLE;
			return PARSING_DADC_SUCCESSFULL;
			break;
		}
	}

	return PARSING_DADC_SUCCESSFULL;
}

int createBlockParams(int blockn, int idsnum) {

	adids = idsnum ;
	idn = idsnum;
	std::vector<instruct> p;
	int inad = 0;
	int sumc = 0;
	int sumo = 0;

	if (ids[idsnum - 1].token == TOKEN_BRACKET_ROUND_CLOSE)
	{
		p.push_back(instruct{});
		while (true)
		{
			//printf("%s\n", "GGGGGGG");
			if (ids[adids].token == TOKEN_BRACKET_ROUND_OPEN)
			{
				sumo++;
				//printf("%s\n", "GGGGGGG");
				if (sumc == sumo)
				{
					//printf("%s\n", "GGGGGGG");
					break;
				}
			//	break;
			}
			if (ids[adids].token == TOKEN_BRACKET_ROUND_CLOSE)
			{
				sumc++;
			}
			adids--;
			if (adids < 0)
			{
				return PARSING_BLOCK_PARAMS_ERROR;
				break;
			}
		}
		
		

		for (int i = adids + 1; i < idsnum - 1; i++)
		{
			if (ids[i].token == TOKEN_INT_TYPE)
			{
				blocks[blocknum].variableLocalByteSize += 4;
			}
			if (ids[i].token == TOKEN_COMMA_SS)
			{
				//std::vector<id> gf;
				
				p.push_back(instruct{});
			    inad++;
				//p[inad]
			}

			if (ids[i].token != TOKEN_END_SS && ids[i].token != TOKEN_BRACKET_ROUND_OPEN && ids[i].token != TOKEN_BRACKET_ROUND_CLOSE && ids[i].token != TOKEN_COMMA_SS)
			{
				p[inad].ins.push_back(ids[i]);
			}

		}
	}

	blocks[blockn].parametrs = p;

	return PARSING_BLOCK_PARAMS_SUCCESSFULL;
}

int defType0(int bl) {

	//bl = bl - 1;
//	printf("%d\n", bl);
	int in = blocks[bl].insblock.size() - 1;

	if (blocks[bl].insblock[in].ins.size() < 1)
	{
		in = blocks[bl ].insblock.size() - 2;
    }
	//printf("%d\n", bl);
	
	switch (blocks[bl].insblock[in].ins[0].token)
	{
	case TOKEN_INT_TYPE:
	    //printf("%s\n", "INTT");
		//if (blocks[bl].insblock[in].ins[1].token == TOKEN_ID && blocks[bl].insblock[in].ins[2].token == TOKEN_BRACKET_ROUND_OPEN)
		//{
			return _COMPILE_ASSEMBLER_FUNCTION;
		//}
		break;
	case TOKEN_IF_WORD:
		//printf("%s\n", "WW");
		return _COMPILE_ASSEMBLER_IF_FUNCTION;
		break;
	default:
		//return _COMPILE_ASSEMBLER_UNDEFINED_ERROR;
		break;
		
	}
	
	return _COMPILE_ASSEMBLER_UNDEFINED_ERROR;
}

int parsing() {
	int adbrc = 0;
	int bb1 = 0;

	for (int i = 0; i < ids.size(); i++)
	{
		
		switch (ids[i].token)
		{
		case TOKEN_BRACKET_CURLY_OPEN:
			if (blocknum == 0)
				bb = blocks.size();

			k = instrnum;
			
			instrnum = 0;
			
			//printf("%s\n", blocks[blocknum].insblock[blocks[blocknum].insblock.size() - 1].ins[0].name.c_str());
			blocks.push_back(block{});
			blocknum = blocks.size() - 1;
		    blocks[blocknum].type0 = defType0(0);
			blocks[blocknum].insblock.push_back(instruct{});
			createBlockParams(blocknum, i);
			//if (ids[adids - 1].token == TOKEN_ID)
			//{
				//printf("%d\n", k);
				//blocks[0].insblock[k].ins.push_back(id{ "", "", PARSING_FUNCTION_W });
		//	}
			
		//	blocks[blocknum].parametrs.push_back(instruct{});
			break;
		case TOKEN_BRACKET_CURLY_CLOSE:
			instrnum = k;
			if (blocknum == bb)
			{
				blocknum = 0;
				bb = 0;
			}
			else
			{
				blocknum--;
			}

			blocks[blocknum].insblock.push_back(instruct{});
			instrnum = blocks[blocknum].insblock.size() - 1;
			break;
		case TOKEN_END_SS:
			blocks[blocknum].insblock.push_back(instruct{});
			instrnum = blocks[blocknum].insblock.size() - 1;
			//instrnum++;
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
			if (ids[i - 1].token == TOKEN_ID)
			{
				adbrc = i;
				std::vector<id> mv1;
				while (true) {
					if (ids[adbrc + 1].token == TOKEN_END_SS)
					{
						break;
					}
					else
					{
					    adbrc++;
						mv1.push_back(ids[adbrc]);
					}
					
				}
				i = adbrc;
				std::vector<id> mv;
				ParsingMathExpr(mv, mv1);
				blocks[blocknum].insblock[instrnum].ins.push_back(id{ "", "=", TOKEN_ASSIGNMENT_SS });
				for (int iggg = 0; iggg < mv.size(); iggg++)
				{
					if (mv[iggg].token != TOKEN_BRACKET_CURLY_CLOSE && mv[iggg].token != TOKEN_BRACKET_CURLY_OPEN && mv[iggg].token != TOKEN_END_SS && mv[iggg].token != TOKEN_BRACKET_ROUND_CLOSE && mv[iggg].token != TOKEN_BRACKET_ROUND_OPEN) {
						blocks[blocknum].insblock[instrnum].ins.push_back(mv[iggg]);
					}
				     
				}
			}
			break;
		case TOKEN_ID:
			
			DADC(i, i);
			//i++;
			break;  
		case TOKEN_IF_WORD:
			if (ids[i + 1].token == TOKEN_BRACKET_ROUND_OPEN)
			{
				ids[i].anndef = _COMPILE_ASSEMBLER_IF_FUNCTION;
			}
			break;
		default:
			break;
		}

		if (ids[i].token != TOKEN_BRACKET_CURLY_CLOSE && ids[i].token != TOKEN_BRACKET_CURLY_OPEN && ids[i].token != TOKEN_END_SS && ids[i].token != TOKEN_BRACKET_ROUND_CLOSE && ids[i].token != TOKEN_BRACKET_ROUND_OPEN )
		{
			if (! (i > adids && i < idn) )
			{
				
				 blocks[blocknum].insblock[instrnum].ins.push_back(ids[i]);
			}
			else
			{
				//printf("%s\n", ids[i].name.c_str());
			}
			
		}

	}

		
		//defType0(0)

	return PARSING_SUCCESSFUL;
}
