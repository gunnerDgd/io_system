#pragma once
#include <stdio.h>
#include <io_system/debug/defined.h>

#ifdef SYNAPSE_IOSYS_DEBUG_MODE
#define synapse_iosys_debug_message(pModule, pStackName, pMsg)\
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [MODULE] %s\n"   , pModule);   \
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [STACK] %s\n"    , pStackName);\
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [MESSAGE] %s\n\n", pMsg)
#else
#define synapse_iosys_debug_message(pModule, pMsg)
#endif

#ifdef SYNAPSE_IOSYS_DEBUG_MODE
#define synapse_iosys_debug_message_value(pModule, pStackName, pVarName, pVarValue)\
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [MODULE] %s\n", pModule);	   \
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [STACK] %s\n" , pStackName) ; \
	printf("[SYNAPSE-IOSYS][DEBUG][MESSAGE] :: [VARIABLE] %s : [VALUE] %08x\n\n", pVarName, pVarValue)
#else
#define synapse_iosys_debug_message_value(pModule, pStackName, pVarName, pVarValue)
#endif