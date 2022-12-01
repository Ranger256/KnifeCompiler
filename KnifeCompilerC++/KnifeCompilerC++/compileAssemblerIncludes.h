#pragma once
#ifndef __INCLUDES_COMPILE_ASSEMBLER_
#define __INCLUDES_COMPILE_ASSEMBLER_

#define _COMPILE_ASSEMBLER_FUNCTION 11
#define _COMPILE_ASSEMBLER_VARIBLE 12
#define _COMPILE_ASSEMBLER_IF_FUNCTION 13
#define _COMPILE_ASSEMBLER_UNDEFINED_ERROR 14

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

