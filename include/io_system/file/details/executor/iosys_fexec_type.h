#pragma once
#include <io_system/file/file_io_system.h>
#include <structure/queue/linear/linear_queue.h>
#include <context/all.h>

#include <stdbool.h>

typedef struct __synapse_iosys_fexec
{
	synapse_context_default_entity fexec_context;
	synapse_structure_linear_queue fexec_queue  ;
} __synapse_iosys_fexec;