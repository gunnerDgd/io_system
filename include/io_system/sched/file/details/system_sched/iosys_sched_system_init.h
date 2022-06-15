#pragma once
#include <io_system/sched/file/details/system_sched/iosys_sched_system_type.h>

__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize		   (size_t);

__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize_default();

void
__synapse_iosys_sched_system_cleanup		   (__synapse_iosys_sched_system*);