#include "stdafx.h"
#include "MathParser.h"

void CreatePreorOP(std::map<int, int> &prs) {
	prs[TOKEN_PLUS_OPERATOR] = 1;
	prs[TOKEN_MINUS_OPERATOR] = 1;
	prs[TOKEN_MULTIPLAY_OPERATOR] = 2;
	prs[TOKEN_DIVISION_OPERATOR] = 2;
}

int CreatePostfixTokens(std::vector<id> &inse, std::vector<id> insl) {
	std::map<int, int> priorOP;
	CreatePreorOP(priorOP);
	std::stack<id> st;

	for (int i = 0; i < insl.size(); i++)
	{
		//st.push(insl[i]);

		switch (insl[i].token)
		{
		case TOKEN_INT_VALUE:
		//	st.push(insl[i]);
			inse.push_back(insl[i]);
			break;
		case TOKEN_ID:
			inse.push_back(insl[i]);
			break;
		case TOKEN_BRACKET_ROUND_OPEN:
			st.push(insl[i]);
			break;
		case TOKEN_BRACKET_ROUND_CLOSE:
			while (st.top().token != TOKEN_BRACKET_ROUND_OPEN)
			{
				inse.push_back(st.top());
				st.pop();
			}
			st.pop();
			break;
		case TOKEN_PLUS_OPERATOR:
			
			if (st.size())
			{
				while (st.size() && ( (st.top().token == TOKEN_PLUS_OPERATOR || st.top().token == TOKEN_MINUS_OPERATOR || st.top().token == TOKEN_DIVISION_OPERATOR || st.top().token ==  TOKEN_MULTIPLAY_OPERATOR) && priorOP[TOKEN_PLUS_OPERATOR] <= priorOP[st.top().token]) )
				{
					inse.push_back(st.top());
					st.pop();
				}
			}
			st.push(insl[i]);
			break;
		case TOKEN_MINUS_OPERATOR:
			if (st.size())
			{
				while (st.size() && ((st.top().token == TOKEN_PLUS_OPERATOR || st.top().token == TOKEN_MINUS_OPERATOR || st.top().token == TOKEN_DIVISION_OPERATOR || st.top().token == TOKEN_MULTIPLAY_OPERATOR) && priorOP[TOKEN_MINUS_OPERATOR] <= priorOP[st.top().token]))
				{
					inse.push_back(st.top());
					st.pop();
				}
			}
			st.push(insl[i]);
			break;
		case TOKEN_MULTIPLAY_OPERATOR:
			if (st.size())
			{
				while (st.size() && ((st.top().token == TOKEN_PLUS_OPERATOR || st.top().token == TOKEN_MINUS_OPERATOR || st.top().token == TOKEN_DIVISION_OPERATOR || st.top().token == TOKEN_MULTIPLAY_OPERATOR) && priorOP[TOKEN_MULTIPLAY_OPERATOR] <= priorOP[st.top().token]))
				{
					inse.push_back(st.top());
					st.pop();
				}
			}
			st.push(insl[i]);
			break;
		case TOKEN_DIVISION_OPERATOR:
			if (st.size())
			{
				while (st.size() && ((st.top().token == TOKEN_PLUS_OPERATOR || st.top().token == TOKEN_MINUS_OPERATOR || st.top().token == TOKEN_DIVISION_OPERATOR || st.top().token == TOKEN_MULTIPLAY_OPERATOR) && priorOP[TOKEN_DIVISION_OPERATOR] <= priorOP[st.top().token]))
				{
					inse.push_back(st.top());
					st.pop();
				}
			}
			st.push(insl[i]);
			break;
		default:
			break;
		}

	}

	while (st.size())
	{
		inse.push_back(st.top());
		st.pop();
	}

	return PARSING_MATH_CREATE_POSTFIX_TOKENS_SUCCESSFULL;
}

int ParsingMathExpr(std::vector<id> &inse, std::vector<id> insl) {

	std::stack<id> st;
	std::vector<id> vt;

	CreatePostfixTokens(vt, insl);

	for (int i = 0; i < vt.size(); i++)
	{

		switch (vt[i].token)
		{
		case TOKEN_INT_VALUE:
			st.push(vt[i]);
			break;
		case TOKEN_ID:
			st.push(vt[i]);
			break;
		case TOKEN_PLUS_OPERATOR:
			if (st.top().token != TOKEN_ID)
			{
				std::stack<id> stdop;
				stdop.push(st.top());
				st.pop();
				if (st.top().token != TOKEN_ID)
				{
					st.push(stdop.top());
					st.push(op_plus(st));
				}
				else
				{
					st.push(stdop.top());
					st.push(id{"", "+", TOKEN_PLUS_OPERATOR});
				}
			}
			else
			{
				st.push(id{ "", "+", TOKEN_PLUS_OPERATOR });
			}
			break;
		case TOKEN_MULTIPLAY_OPERATOR:
			if (st.top().token != TOKEN_ID)
			{
				std::stack<id> stdop;
				stdop.push(st.top());
				st.pop();
				if (st.top().token != TOKEN_ID)
				{
					st.push(stdop.top());
					st.push(op_mul(st));
				}
				else
				{
					st.push(stdop.top());
					st.push(id{ "", "*", TOKEN_PLUS_OPERATOR });
				}
			}
			else
			{
				st.push(id{ "", "*", TOKEN_PLUS_OPERATOR });
			}
			break;
		case TOKEN_MINUS_OPERATOR:
			if (st.top().token != TOKEN_ID)
			{
				std::stack<id> stdop;
				stdop.push(st.top());
				st.pop();
				if (st.top().token != TOKEN_ID)
				{
					st.push(stdop.top());
					st.push(op_minus(st));
				}
				else
				{
					st.push(stdop.top());
					st.push(id{ "", "-", TOKEN_PLUS_OPERATOR });
				}
			}
			else
			{
				st.push(id{ "", "-", TOKEN_PLUS_OPERATOR });
			}
			break;
		case TOKEN_DIVISION_OPERATOR:
			if (st.top().token != TOKEN_ID)
			{
				std::stack<id> stdop;
				stdop.push(st.top());
				st.pop();
				if (st.top().token != TOKEN_ID)
				{
					st.push(stdop.top());
					st.push(op_div(st));
				}
				else
				{
					st.push(stdop.top());
					st.push(id{ "", "/", TOKEN_PLUS_OPERATOR });
				}
			}
			else
			{
				st.push(id{ "", "/", TOKEN_PLUS_OPERATOR });
			}
			break;
		default:
			break;
		}

	}

	while (st.size())
	{
		inse.push_back(st.top());
		st.pop();
	}

	return PARSING_MATH_EXPR_SUCCESSFULL;
}