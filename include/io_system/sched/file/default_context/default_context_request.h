#pragma once
#include <io_system/sched/file/default_context/default_context_type.h>

void
synapse_iosys_sched_default_context_dispatch_read
	(synapse_iosys_sched_default_context*, synapse_iosys_sched_default_context_io_request*);

void
synapse_iosys_sched_default_context_dispatch_write
	(synapse_iosys_sched_default_context*, synapse_iosys_sched_default_context_io_request*);