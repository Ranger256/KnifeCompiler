#pragma once
#ifndef _IF_ASM_
#define _IF_ASM_

#include "compileAssemblerIncludes.h"
#include "CompilerAssembler.h"

#define _COMPILE_ASSEMBLER_IF_SUCCESSFULL 19
#define _COMPILE_ASSEMBLER_IF_ERROR 20

int CompileIfWordAnnToASM(int _blockst, int inst, int k);
int CompileIfWordDefToASM(int _blockst, int inst, int k);

int CompileIfWordGreaterToASM(int _blockst, int inst, int k);
int CompileIfWordLessToASM(int _blockst, int inst, int k);
int CompileIfWordEqualToASM(int _blockst, int inst, int k);

#endif // _IF_ASM_

