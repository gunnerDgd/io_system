#pragma once
#include <io_system/sched/file/details/default_context/iosys_sched_context_type.h>

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_retrive_completed
	(__synapse_iosys_sched_default_context*);

void
__synapse_iosys_sched_default_context_dispatch_read
	(__synapse_iosys_sched_default_context*, 
	 __synapse_iosys_sched_default_context_io_request*);

void
__synapse_iosys_sched_default_context_dispatch_write
	(__synapse_iosys_sched_default_context*, 
	 __synapse_iosys_sched_default_context_io_request*);