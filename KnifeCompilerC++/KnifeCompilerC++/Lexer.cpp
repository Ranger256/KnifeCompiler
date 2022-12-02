#include "stdafx.h"
#include "Lexer.h"
#define TYPE_VALUE_CONST(s) if (!s.empty() || ((isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {	char* p;strtol(s.c_str(), &p, 10);if (*p == 0) return TOKEN_INT_VALUE;strtod(s.c_str(), &p);if (*p == 0.0f)return TOKEN_DOUBLE_VALUE;}

int TypeValueConst(std::string s) {
	if (!s.empty() || ((isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
		char* p;
		strtol(s.c_str(), &p, 10);
		if (*p == 0) return TOKEN_INT_VALUE;

		strtod(s.c_str(), &p);
		if (*p == 0.0f)
			return TOKEN_DOUBLE_VALUE;
	}
	return 0;
}

int lexan(std::string s) {
	//symbols
	if (s == ";")
	{
		return TOKEN_END_SS;
	}
	if (s == ".")
	{
		return TOKEN_DOT_SS;
	}
	if (s == ",")
	{
		return TOKEN_COMMA_SS;
	}
	if (s == "+")
	{
		return TOKEN_PLUS_OPERATOR;
	}
	if (s == "-")
	{
		return TOKEN_MINUS_OPERATOR;
	}
	if (s == "/")
	{
		return TOKEN_DIVISION_OPERATOR;
	}
	if (s == "*")
	{
		return TOKEN_MULTIPLAY_OPERATOR;
	}
	if (s == " ")
	{
		return TOKEN_SPACE_SS;
	}
	if (s == "(")
	{
		return TOKEN_BRACKET_ROUND_OPEN;
	}
	if (s == ")")
	{
		return TOKEN_BRACKET_ROUND_CLOSE;
	}
	if (s == "{")
	{
		return TOKEN_BRACKET_CURLY_OPEN;
	}
	if (s == "}")
	{
		return TOKEN_BRACKET_CURLY_CLOSE;
	}
	if (s == "[")
	{
		return TOKEN_BRACKET_SQUARE_OPEN;
	}
	if (s == "]")
	{
		return TOKEN_BRACKET_SQUART_CLOSE;
	}
	if (s == "=")
	{
		return TOKEN_ASSIGNMENT_SS;
	}
	TYPE_VALUE_CONST(s);
	//keywords

	if (s == "if")
	{
		return TOKEN_IF_WORD;
	}
	if (s == "else")
	{
		return TOKEN_ELSE_WORD;
	}
	if (s == "return")
	{
		return TOKEN_RETURN;
	}
	
	//types

	if (s == "bool")
		return TOKEN_BOOL_TYPE;
	

	if (s == "int")return TOKEN_INT_TYPE;
	if (s == "double")return TOKEN_DOUBLE_TYPE;

	//values
	if (s == "true" || s == "false") return TOKEN_BOOL_VALUE;

	int p = getID(s);

		if (p > 0)
		{

			return TOKEN_ID;
		}
		else if (p == 0) {
			if (ids.size() > 0)
			{
				int b = ids.size() - 2;
				if (b >= 0)
				{
					if (ids[b].token == TOKEN_INT_TYPE || ids[b].token == TOKEN_DOUBLE_TYPE)
					{
					return TOKEN_TYPE_ID_ERROR;
					}
					else {
						switch (ids[ids.size() - 1].token)
						{
						case TOKEN_INT_TYPE:
							insert("", s, TOKEN_INT_TYPE);
							return TOKEN_ID;
							break;
						case TOKEN_DOUBLE_TYPE:
							insert("", s, TOKEN_DOUBLE_TYPE);
							return TOKEN_ID;
							break;
						default:
							return TOKEN_TYPE_ID_ERROR;
							break;
						}
					}
				}
				else
				{
					switch (ids[ids.size() - 1].token)
					{
					case TOKEN_INT_TYPE:
						insert("", s, TOKEN_INT_TYPE);
						return TOKEN_ID;
						break;
					case TOKEN_DOUBLE_TYPE:
						insert("", s, TOKEN_DOUBLE_TYPE);
						return TOKEN_ID;
						break;
					default:
						return TOKEN_TYPE_ID_ERROR;
						break;
					}
				}
			}

		}

	return 0;
}

void insert(std::string value, std::string name, int token) {
	if (ids.size() > 0)
	{
		for (int i = 0; i < ids.size(); i++)
		{
			if (ids[i].name == name)
			{
				id  ID = id{ value, name, token };
				ids.push_back(ID);
				//printf("%s", ids[ids.size() - 1].name.c_str());
			}
		}
	}
	else
	{
		id  ID = id{ value, name, token };
		ids.push_back(ID);
		//printf("%s", ids[ids.size() - 1].name.c_str());
	}
}

int getID(std::string s) {
	for (int i = 0; i < ids.size(); i++)
	{
		if (ids[i].name == s)
		{
			return ids[i].token;
		}
	}

	return 0;

}

void razd(char c,std::string d, std::string *s, int i);
void razd(char c,std::string d, std::string *s, int i) {
	if (d[i] == c || d[i - s->length()] == c)
	{
	   if (*s != "" && *s != " ")
		{
			ids.push_back(id{ "", *s, lexan(*s) });
			//printf("%s\n", s->c_str());
			*s = "";
		}
				
	} 
}

void lexanCode(std::string d) {
	std::string s = "";
	bool zap = true;


	for (int i = 0; i < d.length(); i++)
	{
		for (int j = 0; j < (sizeof(ss) / sizeof(char)); j++)
		{
			razd(ss[j], d, &s, i);
		}

		if (d[i] == ' ' || d[i] == '\t')
		{
			if (s != "" && s != " " && s != "\t")
			{
				if (zap) {
					//printf("%s\n", s.c_str());
				    ids.push_back(id{ "", s, lexan(s) });
					//s = "";
				}
				
			}
			if (zap)
			s = "";

		}
		else if (d[i] == '\n' || d[i] == '\t') {
			zap = true;
			if (s != "" && s != " " && s != "\t")
			{
				if (zap) {
					
						ids.push_back(id{ "", s, lexan(s)});
					s = "";
				}
			}

			if (zap)
			s = "";

		}
		else if ( (d[i] == '/' && d[i + 1] == '/') || d[i] == '\t') {
			printf("%s\n", "gg");
			if (s != "" && s != " " && s != "\t")
			{
				if (zap) {
						ids.push_back(id{ "", s, lexan(s)});
					s = "";
				}
			}
			if (zap)
			s = "";

			zap = false;

		}
		else if ((d[i] == '/' && d[i + 1] == '*') || d[i] == '\t') {
			printf("%s\n", "gg");
			if (s != "" && s != " " && s != "\t")
			{
				if (zap) {
				
					ids.push_back(id{ "", s, lexan(s) });
					s = "";
				}

			}
			if (zap)
				s = "";

			zap = false;

		}
		else if ((d[i] == '/' && d[i-1] == '*') || d[i] == '\t') {
			zap = true;
		}
		else
		{
			if (zap)
			{
				s += d[i];
			}
			

			if (i == d.length() - 1 && s != " ")
			{
				if (zap) {
						ids.push_back(id{ "", s, lexan(s) });
					s = "";
				}
			//	printf("%s", s.c_str());
			}
		}
		if (d[i] == '\n')
		{
			lines++;
		}
	}



}
