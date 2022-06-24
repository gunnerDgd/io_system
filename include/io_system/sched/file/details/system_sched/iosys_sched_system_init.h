#pragma once
#include <io_system/sched/file/details/system_sched/iosys_sched_system_type.h>
#include <io_system/file/details/native/async_io/iosys_file_native_aio_type.h>

__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize
	(size_t);

__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize_default
	();

__synapse_iosys_sched_system_io_session*
__synapse_iosys_sched_system_io_session_initialize
	(__synapse_iosys_sched_system*, __synapse_io_system_file_aio*);

void
__synapse_iosys_sched_system_io_session_cleanup
	(__synapse_iosys_sched_system_io_session*);

void
__synapse_iosys_sched_system_cleanup
	(__synapse_iosys_sched_system*);