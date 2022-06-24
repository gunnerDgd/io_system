#pragma once
#include <io_system/sched/file/details/system_sched/iosys_sched_system_type.h>

void
__synapse_iosys_sched_system_io_request_dispatch_read
	(__synapse_iosys_sched_system_io_session*, 
	 __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_dispatch_write
	(__synapse_iosys_sched_system_io_session*, 
	 __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_do_completion
	(DWORD, DWORD, LPOVERLAPPED);