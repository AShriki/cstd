#ifndef __BASE_MACRO__
#define __BASE_MACRO__

#define L1(uniq,typeName) uniq##typeName
#define L2(uniq,typeName) L1(uniq,typeName)
#define GENERATE_STRUCT_ID(uniq,typeName) L2(uniq,typeName)

#endif  