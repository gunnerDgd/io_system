#pragma once
#include <io_system/sched/file/details/default_context/iosys_sched_context_type.h>

__synapse_iosys_sched_default_context*
__synapse_iosys_sched_default_context_initialize();

void
__synapse_iosys_sched_default_context_cleanup   (__synapse_iosys_sched_default_context*);

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_io_request_initialize
	(synapse_io_system_file*, void*, size_t, size_t);

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_io_request_initialize_from_existing
	(__synapse_iosys_sched_default_context_io_request*,
	 synapse_io_system_file*,
	 void* ,
	 size_t,
     size_t);

void
__synapse_iosys_sched_default_context_io_request_cleanup
	(__synapse_iosys_sched_default_context_io_request*);