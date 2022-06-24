#pragma once
#include <io_system/sched/file/details/system_sched/iosys_sched_system_type.h>

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize
	(void*, size_t, size_t);

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize_from_existing
	(__synapse_iosys_sched_system_io_request*, void*, size_t, size_t);

void
__synapse_iosys_sched_system_io_request_cleanup
	(__synapse_iosys_sched_system_io_request*);