#pragma once
#include <io_system/file/details/executor/iosys_fexec_io_type.h>
#include <io_system/file/details/executor/iosys_fexec_type.h>

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize		(synapse_context_default_entity*);

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize_default();

void
__synapse_iosys_fexec_cleanup			(__synapse_iosys_fexec*);