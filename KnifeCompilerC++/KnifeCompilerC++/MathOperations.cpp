#include "stdafx.h"
#include "MathOperations.h"

id op_plus(std::stack<id> &idses2) {

	double ch = std::atoi( idses2.top().name.c_str() );
	int ttc1 = idses2.top().token;
	idses2.pop();
	double ch1 = std::atoi(idses2.top().name.c_str());
	idses2.pop();

	if (ttc1 == TOKEN_INT_VALUE)
	{
		int ret = ch + ch1;

		return id{ "", std::to_string(ret), TOKEN_INT_VALUE };
	}

}

id op_minus(std::stack<id> &idses2) {
	double ch = std::atoi(idses2.top().name.c_str());
	int ttc1 = idses2.top().token;
	idses2.pop();
	double ch1 = std::atoi(idses2.top().name.c_str());
	idses2.pop();

	if (ttc1 == TOKEN_INT_VALUE)
	{
		int ret = ch1 - ch;

		return id{ "", std::to_string(ret), TOKEN_INT_VALUE };
	}
}

id op_mul(std::stack<id> &idses2) {

	double ch = std::atoi(idses2.top().name.c_str());
	int ttc1 = idses2.top().token;
	idses2.pop();
	double ch1 = std::atoi(idses2.top().name.c_str());
	idses2.pop();

	if (ttc1 == TOKEN_INT_VALUE)
	{
		int ret = ch * ch1;

		return id{ "", std::to_string(ret), TOKEN_INT_VALUE };
	}

}

id op_div(std::stack<id> &idses2) {
	double ch = std::atoi(idses2.top().name.c_str());
	int ttc1 = idses2.top().token;
	idses2.pop();
	double ch1 = std::atoi(idses2.top().name.c_str());
	idses2.pop();

	if (ttc1 == TOKEN_INT_VALUE)
	{
		int ret = ch1 / ch;

		return id{ "", std::to_string(ret), TOKEN_INT_VALUE };
	}
}