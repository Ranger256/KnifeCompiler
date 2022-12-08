#pragma once
#ifndef __MATH_OPERATIONS__
#define __MATH_OPERATIONS__

#include "Lexer.h"
#include <vector>
#include <stack>

id op_plus(std::stack<id> &idses2);
id op_minus(std::stack<id> &idses2);
id op_mul(std::stack<id> &idses2);
id op_div(std::stack<id> &idses2);

#endif // !__MATH_OPERATIONS__

