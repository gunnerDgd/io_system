#pragma once
#include <io_system/sched/file/details/system_sched/\iosys_sched_system_type.h>
#include <stdbool.h>

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize
	(__synapse_iosys_file_native*, size_t, size_t);

void
__synapse_iosys_sched_system_io_request_cleanup
	(__synapse_iosys_sched_system_io_request*);

bool
__synapse_iosys_sched_system_io_request_poll(__synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_register
	(__synapse_iosys_sched_system*, __synapse_iosys_file_native*);

void
__synapse_iosys_sched_system_io_request_dispatch_read
	(__synapse_iosys_sched_system*, __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_dispatch_write
(__synapse_iosys_sched_system*, __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_cancel
	(__synapse_iosys_sched_system*, __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_wait	  
	(__synapse_iosys_sched_system*, __synapse_iosys_sched_system_io_request*);

void
__synapse_iosys_sched_system_io_request_wait_until
	(__synapse_iosys_sched_system*, __synapse_iosys_sched_system_io_request*, uint64_t);