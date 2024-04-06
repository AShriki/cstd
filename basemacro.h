#ifndef __BASE_MACRO__
#define __BASE_MACRO__

#include <stddef.h>

#ifdef NOSTD_MEM
#define free mem_free
#define malloc mem_alloc
#else
#include <stdlib.h>
#endif

#define VOID_PTR (void *)0

#define L1(uniq,typeName) uniq##typeName
#define L2(uniq,typeName) L1(uniq,typeName)
#define GENERATE_STRUCT_ID(uniq,typeName) L2(uniq,typeName)

#endif  