#pragma once
#include <io_system/sched/file/default_context/default_context_type.h>
#include <io_system/file/file_io_system.h>

synapse_iosys_sched_default_context
synapse_iosys_sched_default_context_initialize();

synapse_iosys_sched_default_context_io_request
synapse_iosys_sched_default_context_io_request_initialize
	(synapse_io_system_file*, void*, size_t, size_t);

synapse_iosys_sched_default_context_io_request
synapse_iosys_sched_default_context_io_request_initialize_from_existing
	(synapse_iosys_sched_default_context_io_request,
	 synapse_io_system_file*,
	 void*, size_t, size_t);

void
synapse_iosys_sched_default_context_cleanup
	(synapse_iosys_sched_default_context);

void
synapse_iosys_sched_default_context_io_request_cleanup
	(synapse_iosys_sched_default_context_io_request);