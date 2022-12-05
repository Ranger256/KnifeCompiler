#pragma once
#ifndef __INCLUDES_COMPILE_ASSEMBLER_
#define __INCLUDES_COMPILE_ASSEMBLER_

#define _COMPILE_ASSEMBLER_FUNCTION 11
#define _COMPILE_ASSEMBLER_NEW_VARIBLE 12
#define _COMPILE_ASSEMBLER_SET_VARIABLE 28
#define _COMPILE_ASSEMBLER_TAKE_VALUE_VARIABLE 29
#define _COMPILE_ASSEMBLER_IF_FUNCTION 13
#define _COMPILE_ASSEMBLER_UNDEFINED_ERROR 14

#define _COMPILE_ASSEMBLER_DEFINED 15
#define _COMPILE_ASSEMBLER_ANNOUNCEMENT 16
#define _COMPILE_ASSEMBLER_CALLING 23



#include "Parser.h"
#include <map>

struct symb {
	int type0;
	int type;
	bool global;
	int numStackLocal;
};

extern std::map<std::string, symb> tablsymb;

extern std::string codeAssembler;

#endif // !__INCLUDES__

