#pragma once
#include <io_system/sched/file/details/default_context/iosys_sched_context_type.h>

__synapse_iosys_sched_default_context*
__synapse_iosys_sched_default_context_initialize();

void
__synapse_iosys_sched_default_context_cleanup   (__synapse_iosys_sched_default_context*);